package message

import (
	_ "embed"
	"errors"
	"os"
	"strings"
	"text/template"
	"vlcb/codegen/netmsg/opcode"
	"vlcb/codegen/pkg/arrays"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_c "github.com/tree-sitter/tree-sitter-c/bindings/go"
)

//go:embed template/message.h
var messageTemplate string

const OPC_FILE_PATH = "../../../modules/common/inc/vlcb/common/opcode.h"
const MESSAGE_FILE_PATH = "../../../modules/net/inc/vlcb/net/packet/data.h"

type GenerateMessages struct {
}

func (c *GenerateMessages) Run() error {

	if _, err := os.Stat(OPC_FILE_PATH); err != nil {
		return err
	}

	if _, err := os.Stat(MESSAGE_FILE_PATH); err == nil {
		return errors.New("generated message file already exists")
	}

	parser := tree_sitter.NewParser()
	defer parser.Close()
	parser.SetLanguage(tree_sitter.NewLanguage(tree_sitter_c.Language()))

	var sourceCodeBuf []byte
	var tree *tree_sitter.Tree
	{
		if file, err := os.Open(OPC_FILE_PATH); err == nil {
			defer file.Close()
			fileinfo, err := file.Stat()
			if err != nil {
				return err
			}
			sourceCodeBuf = make([]byte, fileinfo.Size())
			if _, err := file.Read(sourceCodeBuf); err != nil {
				return err
			}
		} else {
			return err
		}

		tree = parser.Parse(sourceCodeBuf, nil)
	}

	tmpl, err := template.New("message").Parse(messageTemplate)
	if err != nil {
		return err
	}

	opcodeNode := opcode.FindOpcodeEnum(tree, sourceCodeBuf)
	opcodes := opcode.ExtractOpcodes(opcodeNode, sourceCodeBuf)

	opcodes = arrays.Filter(opcodes, func(o opcode.Opcode) bool { return o.DataLen > 0 })

	messages := make([]Message, len(opcodes))
	for i, o := range opcodes {
		messages[i] = getMessageForOpcode(o)
	}

	var rendered strings.Builder

	for _, m := range messages {
		tmpl.Execute(&rendered, m)
		rendered.WriteRune('\n')
	}

	if file, err := os.Create(MESSAGE_FILE_PATH); err == nil {
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
