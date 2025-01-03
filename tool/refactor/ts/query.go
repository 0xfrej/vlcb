//go:embed query/*
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
)

var query embed.FS

func OpenQuery(queryName TSQuery, language *tree_sitter.Language) (*tree_sitter.Query, error) {
	file, err := query.ReadFile(path.Join("query", string(queryName)))
	if err != nil {
		return nil, fmt.Errorf("could not open query '%s': %w", queryName, err)
	}

	return tree_sitter.NewQuery(language, string(file))
}
