design details:
	- top level functions should NOT be loaded into memory unless explicitly called
	- domain specific details should be very conservative. a node on the binary computation tree should align with a single ident or numerical constant
	- IO should be via lambda expressions, with the input or output of the lambda expression being redirected.
	- the entry point should be a predetermined function, pointed at by the ast tree head. the repl should point this differently somehow(?)

lambdex should:
	- follow the functional paradigm closely, only deviating from the paradigm when necessary -- that is, a capability that must deviate in order to be available to the language

lambdex is designed to use:
	- lazy evaluation
	- type inference
	- strong typing -- casts should be used when otherwise incompatible data types are joined
	- the lambdex language should rely on the interpreter as little as possible, using lambda expressions in favor of domain specific features

lambdex = lambda with expressions

internal steps in running a .lx program:
	- source file is loaded into buffer
	- buffer is prepared by removing whitespaces, comments
	- buffer is converted into an ordered token list. the token list is composed of two ordered linked lists -- one for the morpheme, one for the token
	- control node is allocated (it is NOT an ast node)
	- identifiers + definitions (as token list!!) are linked into symbol table
		* identifiers (function identifiers and variable identifiers are treated equally) are added to symbol table (contained within the control node)
		* identifiers include: {function/variable} idents and entry identifier
	- identifier with token for entry point is located and linked to controller
	- parsing for the entry point begins. ast nodes are created from tokens via formal grammar
		* when an ident is found, the definition is linked via the parser
	
	* while parsing is happening, the binary table of computation should be created to hold the values of arithmetic computations.
	* branches should occur at idents. lambdas should be expanded.


	notes: control node = controller (not an ast node), ident node = top level nodes (symbol table nodes, ast node = actual ast nodes used for parsing

	*make program more modular by separating tasks into separate processes? that way, each component can be debugged independently? also can run parts (preprocess, lex, etc...) concurrently

tokens:
	- ident: identifier for an icast, dcast, iconst, dconst, complex lambda, reduced lambda, zero argument lambda, ident, list, or any combination thereof
	- complex lambda: lambda expression with more than one input. needs reduction
	- reduced lambda: lambda expression that takes one input
	- zero argument lambda: lambda expression that takes no input
	- list: syntax sugar for parenthesized {iconst|dconst}
	- iconst: integer constant
	- dconst: decimal constant
	- icast: cast $const to iconst
	- dcast: cast $const to dconst
