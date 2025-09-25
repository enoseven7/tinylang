# TinyLang

TinyLang is a small, interpreted programming language developed in C++, and a small project by a highschool student. It currently supports:
- Variable declaration (`let x = 5;`)
- Print statements (`print(x + 2);`)
- Arithmetic expressions with `+`, `-`, `*`, `/` and parentheses
- Full interpretation of code (lexer -> parser -> AST -> interpreter)

## Features

- Lexer: Converts source code into tokens
- Parser: Converts tokens into an Abstract Syntax Tree (AST)
- AST supports assignments, print statements, and binary operations
- Interpreter: Executes TinyLang program and prints output

## How to Use

1. Clone the repo:
	```bash
	git clone https://github.com/enoseven7/tinylang.git

2. Open the solution in Visual Studio (tinylang.sln)

3. Build and run "tinylang.cpp"

4. Modify "tinylang.cpp" to test new code snippets

## Planned Features

- Support for more operators and expression types
- Variable scoping and block support
- Functions and return statements
- Enhanced error handling with detailed messages
- Built-in standard library functions

## How it works

Tinylang follows a simple compiler/interpreter architecture:
1. **Lexer**: The lexer reads the source code character by character and groups them into "tokens" (like keywords, identifiers, numbers, operators, etc.)
2. **Parser**: The parser takes the list of tokens and builds an Abstract Syntax Tree (AST) that represents the structure of the code.
3. **Interpreter**: The interpreter walks the AST and executes the code.

## Author

This project was created by a highschool student named Ethan Ngwa, and is part of my portfolio to showcase my skills and knowledge of C++ and programming language concepts.
My full portfolio can be found at https://ngwaethan.vercel.app
Feel free to reach out to me for any inquiries or collaborations.
Feel free to fork and modify this project as you see fit.