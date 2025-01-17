package opcode

type Opcode struct {
	EnumName string
	RawValue uint8
	DataLen  uint8
	Value    uint8
	Comment  string
}

func ExtractDataLenFromRawOpcode(v uint8) uint8 {
	return (v >> 5) & 0x07
}

func ExtractValueFromRawOpcode(v uint8) uint8 {
	return v & 0x1F
}
