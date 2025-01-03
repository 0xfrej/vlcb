package main

import (
	"os"
	"vlcb/refactor/ts"

	"github.com/alecthomas/kong"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_c "github.com/tree-sitter/tree-sitter-c/bindings/go"
)

var CLI struct {
	Path string `arg:"" name:"path" help:"Path to C source file to be split into separate ones" type:"path"`
}

func main() {
	kong.Parse(&CLI)
	sourceFilePath := CLI.Path

	if _, err := os.Stat(sourceFilePath); err != nil {
		panic(err)
	}

	parser := tree_sitter.NewParser()
	defer parser.Close()
	parser.SetLanguage(tree_sitter.NewLanguage(tree_sitter_c.Language()))
	query, err := ts.OpenQuery(ts.TS_QUERY_FUNCTION_DEFINITION, parser.Language())
	if err != nil {
		panic(err)
	}
	defer query.Close()

	var root *tree_sitter.Tree
	{
		var buf []byte
		if file, err := os.Open(sourceFilePath); err == nil {
			if _, err := file.Read(buf); err != nil {
				panic(err)
			}
		} else {
			panic(err)
		}

		root = parser.Parse(buf, nil)
	}

	cursor := tree_sitter.NewQueryCursor()
	matches := cursor.Matches(query, root.RootNode(), nil)

}
