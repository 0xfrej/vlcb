# Codegen - Net message and serialization generator

Generates message types and serialization for them from opcode enum. This is not fully automated and requires some
manual work.

## Do not re-run!!!
this tool doesn't have logic to ignore already generated code at the moment


Steps:

1) Generate Message skeleton `struct`s for each opcode
    this omits opcodes with no data
2) Manually define fields for each message
3) Generate serialization/deserialization methods
4) Generate docs on opcode enum fields with references
