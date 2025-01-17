[
    (
        (comment)? @function.comment
        (function_definition
            declarator: (function_declarator
            declarator: (identifier) @function.name)
            body: (compound_statement) @function.body
        )
    ) @function
]
