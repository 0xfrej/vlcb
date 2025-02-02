package main

import (
	"vlcb/codegen/netmsg/message"
	"vlcb/codegen/netmsg/serialization"

	"github.com/alecthomas/kong"
)

var CLI struct {
	// Path string `arg:"" name:"path" help:"Path to C source file to be split into separate ones" type:"path"`

	GenerateMessages                       message.GenerateMessages                             `cmd:"" help:"Step 1. of the network message structure codegen. Generates messages based on opcodes defined in the project"`
	GenerateSerializerFunctionDeclarations serialization.GenerateSerializerFunctionDeclarations `cmd:"" help:"Step 2. of the network message codegen. Generates function declarations for serialize/deserialize methods"`
}

func main() {
	ctx := kong.Parse(&CLI)

	err := ctx.Run()
	ctx.FatalIfErrorf(err)
}
