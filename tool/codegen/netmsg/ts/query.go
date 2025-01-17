package ts

import (
	"embed"
	"fmt"
	"path"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
)

type TSQuery string

var (
	TS_QUERY_FUNCTION_DEFINITION TSQuery = "function_definition.scm"
	TS_QUERY_OPCODES_ENUM        TSQuery = "opcodes_enum.scm"
	TS_QUERY_OPCODES             TSQuery = "opcodes.scm"
)

//go:embed query/*
var query embed.FS

func OpenQuery(queryName TSQuery, language *tree_sitter.Language) (*tree_sitter.Query, error) {
	file, err := query.ReadFile(path.Join("query", string(queryName)))
	if err != nil {
		return nil, fmt.Errorf("could not open query '%s': %w", queryName, err)
	}

	q, e := tree_sitter.NewQuery(language, string(file))

	if e != nil {
		panic(e)
	}
	return q, nil
}

func GetCaptureName(query *tree_sitter.Query, capture *tree_sitter.QueryCapture) string {
	return query.CaptureNames()[capture.Index]
}

func GetCaptureIndex(query *tree_sitter.Query, name string) uint {
	i, ok := query.CaptureIndexForName(name)
	if !ok {
		panic(fmt.Sprintf("could not find capture '%s'", name))
	}
	return i
}
