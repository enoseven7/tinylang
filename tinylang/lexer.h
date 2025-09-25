#pragma once
#include <string>

enum class TokenType {
	LET,
	IDENT,
	NUMBER,
	EQUAL,
	SEMICOLON,
	PRINT,
	PLUS, MINUS, STAR, SLASH,
	LPAREN, RPAREN,
	END_OF_FILE
};

struct Token {
	TokenType type;
	std::string lexeme;
};