package message

import "vlcb/codegen/netmsg/opcode"

type Message struct {
	Name        string
	OpcEnumName string
}

func getMessageForOpcode(opc opcode.Opcode) Message {
	return Message{
		Name:        NameFromOpcode(opc),
		OpcEnumName: opc.EnumName,
	}
}
