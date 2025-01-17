package message

import (
	"strings"
	"vlcb/codegen/netmsg/opcode"
)

func NameFromOpcode(opc opcode.Opcode) string {
	opcName := strings.TrimLeft(opc.EnumName, "VLCB_OPC_")
	opcNameParts := strings.Split(opcName, "_")
	opcNamePartsTransformed := make([]string, len(opcNameParts))
	// var responseSeen bool
	for i, v := range opcNameParts {
		opcNamePartsTransformed[i] = string(v[0]) + strings.ToLower(v[1:])

		// if strings.Contains(v, "RESPONSE") {
		// 	responseSeen = true
		// }
	}

	// if !responseSeen {
	// 	opcNamePartsTransformed = append(opcNamePartsTransformed, "Response")
	// }

	return "VlcbNetData" + strings.Join(opcNamePartsTransformed, "")
}
