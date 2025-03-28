package serialization

import (
	_ "embed"
	"errors"
	// "errors"
	"os"
	"strings"
	"text/template"
	"vlcb/codegen/netmsg/opcode"
	"vlcb/codegen/pkg/arrays"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_c "github.com/tree-sitter/tree-sitter-c/bindings/go"
)

//go:embed template/declaration.h.tmpl
var declarationTemplate string

const OPC_FILE_PATH = "../../../modules/common/inc/vlcb/common/opcode.h"
const MESSAGE_FILE_PATH = "../../../modules/net/inc/vlcb/net/message/data.h"
const SERIALIZATION_FILE_PATH = "../../../modules/net/inc/vlcb/net/message/serialization.h"

type TemplateData struct {
	Serialize struct {
		Brief string
	}
	Deserialize struct {
		Brief string
	}
	New struct {
		Brief string
	}
	Message struct {
		Name   string
		Type   string
		Fields []Field
	}
}

type Field struct {
	Name string
	Type string
}

type GenerateSerializerFunctionDeclarations struct {
}

func (c *GenerateSerializerFunctionDeclarations) Run() error {

	if _, err := os.Stat(OPC_FILE_PATH); err != nil {
		return err
	}

	if _, err := os.Stat(SERIALIZATION_FILE_PATH); err == nil {
		return errors.New("generated serialization file already exists")
	}

	parser := tree_sitter.NewParser()
	defer parser.Close()
	parser.SetLanguage(tree_sitter.NewLanguage(tree_sitter_c.Language()))

	var opcSourceCodeBuf []byte
	var opcTree *tree_sitter.Tree
	{
		if file, err := os.Open(OPC_FILE_PATH); err == nil {
			defer file.Close()
			fileinfo, err := file.Stat()
			if err != nil {
				return err
			}
			opcSourceCodeBuf = make([]byte, fileinfo.Size())
			if _, err := file.Read(opcSourceCodeBuf); err != nil {
				return err
			}
		} else {
			return err
		}

		opcTree = parser.Parse(opcSourceCodeBuf, nil)
	}

	var msgSourceCodeBuf []byte
	var msgTree *tree_sitter.Tree
	{
		if file, err := os.Open(MESSAGE_FILE_PATH); err == nil {
			defer file.Close()
			fileinfo, err := file.Stat()
			if err != nil {
				return err
			}
			msgSourceCodeBuf = make([]byte, fileinfo.Size())
			if _, err := file.Read(msgSourceCodeBuf); err != nil {
				return err
			}
		} else {
			return err
		}

		msgTree = parser.Parse(msgSourceCodeBuf, nil)
	}

	tmpl, err := template.New("declaration").Parse(declarationTemplate)
	if err != nil {
		return err
	}

	opcodeNode := opcode.FindOpcodeEnum(opcTree, opcSourceCodeBuf)
	opcodes := opcode.ExtractOpcodes(opcodeNode, opcSourceCodeBuf)

	opcodes = arrays.Filter(opcodes, func(o opcode.Opcode) bool { return o.DataLen < 1 })

	messages := opcode.FindOpcodeMessages(msgTree, msgSourceCodeBuf)

	var rendered strings.Builder

	rendered.WriteString(`#include "vlcb/net/message/data.h"
#include "vlcb/net/packet/datagram.h"
`)

	for _, m := range messages {
		data := getTmplData(m)
		tmpl.Execute(&rendered, data)
		rendered.WriteRune('\n')
	}

	if file, err := os.Create(SERIALIZATION_FILE_PATH); err == nil {
		defer file.Close()
		_, err = file.WriteString(rendered.String())
		if err != nil {
			return err
		}
	} else {
		return err
	}

	return nil
}

func getTmplData(m opcode.Message) TemplateData {
	var d TemplateData

	d.Message.Name = m.TypeName
	d.Message.Type = m.TypeName
	d.Serialize.Brief = m.TypeName
	d.Deserialize.Brief = m.TypeName

	var fields []Field
	for _, v := range m.Fields {
		fields = append(fields, Field{
			Name: v.Name,
			Type: v.Type,
		})
	}
	d.Message.Fields = fields
	return d
}
