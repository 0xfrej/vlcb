one-time use generator for packet serialization/deserialization methods which will generate them from opcodes
it has to generate structs and method declaration/definition, struct fields will be added manually.
should we separate the methods and opcodes to "namespaces" like we have now ? if so, might be better to separate them at
the enum level so it's easier
the generator should setup some basic template for each function (asserts, returns etc)
