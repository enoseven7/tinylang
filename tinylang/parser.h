#pragma once
#include "lexer.h"
#include "ast.h"
#include <vector>

class Parser {
public:
	Parser(const std::vector<Token>& tokens) : tokens(tokens), pos(0) {}

	ASTNodePtr parse();

private:
	const std::vector<Token>& tokens;
	size_t pos;

	Token peek();
	Token consume(TokenType expected);
	ASTNodePtr parseStatement();
	ASTNodePtr parseExpression();
	ASTNodePtr parseTerm();
	ASTNodePtr parseFactor();
};