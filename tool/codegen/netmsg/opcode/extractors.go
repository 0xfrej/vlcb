package opcode

import (
	"strconv"
	"vlcb/codegen/netmsg/ts"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
)

func FindOpcodeEnum(tree *tree_sitter.Tree, sourceCodeBuf []byte) tree_sitter.Node {
	query, err := ts.OpenQuery(ts.TS_QUERY_OPCODES_ENUM, tree.Language())
	if err != nil {
		panic(err)
	}
	defer query.Close()

	cursor := tree_sitter.NewQueryCursor()
	defer cursor.Close()
	matches := cursor.Matches(query, tree.RootNode(), sourceCodeBuf)
	opcodeMatches := matches.Next()
	if opcodeMatches == nil {
		panic("opcode enum was not found")
	}

	return opcodeMatches.Captures[2].Node // @opcode_enum.enumerators
}

func ExtractOpcodes(opcodeNode tree_sitter.Node, sourceCodeBuf []byte) []Opcode {
	query, err := ts.OpenQuery(ts.TS_QUERY_OPCODES, opcodeNode.Language())
	if err != nil {
		panic(err)
	}
	defer query.Close()

	cursor := tree_sitter.NewQueryCursor()
	defer cursor.Close()

	matches := cursor.Matches(query, &opcodeNode, sourceCodeBuf)

	var opcodes []Opcode

	nameIndex := ts.GetCaptureIndex(query, "opcode.name")
	valueIndex := ts.GetCaptureIndex(query, "opcode.value")
	commentIndex := ts.GetCaptureIndex(query, "opcode.comment")

	for match := matches.Next(); match != nil; match = matches.Next() {
		opc := Opcode{}
		opc.EnumName = string(match.Captures[nameIndex].Node.Utf8Text(sourceCodeBuf))
		v, err := strconv.ParseInt(match.Captures[valueIndex].Node.Utf8Text(sourceCodeBuf), 10, 9)
		if err != nil {
			panic(err)
		}
		opc.RawValue = uint8(v)
		opc.Comment = string(match.Captures[commentIndex].Node.Utf8Text(sourceCodeBuf))
		opc.Value = ExtractValueFromRawOpcode(opc.RawValue)
		opc.DataLen = ExtractDataLenFromRawOpcode(opc.RawValue)
		opcodes = append(opcodes, opc)
	}

	return opcodes
}
