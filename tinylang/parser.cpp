#include "parser.h"
#include <stdexcept>

// Return the current token without consuming it

Token Parser::peek() {
	if (pos < tokens.size())
		return tokens[pos];
	return { TokenType::END_OF_FILE, "" };
}

// Consume the next token if it matches the expected type, otherwise throw an error

Token Parser::consume(TokenType expected) {
	Token t = peek();
	if (t.type != expected)
		throw std::runtime_error("Unexpected token");
	pos++;
	return t;
}

// Recursive descent parsing for expressions with +, -, *, / and parentheses

ASTNodePtr Parser::parse() {
	auto program = std::make_shared<ASTNode>(NodeType::Program);

	while (peek().type != TokenType::END_OF_FILE) {
		program->children.push_back(parseStatement());
	}

	return program;
}

ASTNodePtr Parser::parseStatement() {
	Token t = peek();

	// Handle variable assignment: let x = 5;

	if (t.type == TokenType::LET) {
		consume(TokenType::LET);
		Token var = consume(TokenType::IDENT);
		consume(TokenType::EQUAL);
		auto expr = parseExpression();
		consume(TokenType::SEMICOLON);

		auto node = std::make_shared<ASTNode>(NodeType::Assignment);
		node->value = var.lexeme;
		node->left = expr;
		return node;
	}

	// Handle print statement: print(x + 2);

	else if (t.type == TokenType::PRINT){
		consume(TokenType::PRINT);
		consume(TokenType::LPAREN);
		auto expr = parseExpression();
		consume(TokenType::RPAREN);
		consume(TokenType::SEMICOLON);

		auto node = std::make_shared<ASTNode>(NodeType::Print);
		node->left = expr;
		return node;
	}

	// Unknown statement

	throw std::runtime_error("Unknown statement");
}

// Expression parser

ASTNodePtr Parser::parseExpression() {
	auto node = parseTerm();

	while (peek().type == TokenType::PLUS || peek().type == TokenType::MINUS) {
		Token op = consume(peek().type);
		auto right = parseTerm();
		auto bin = std::make_shared<ASTNode>(NodeType::BinaryOp);
		bin->op = op.lexeme;
		bin->left = node;
		bin->right = right;
		node = bin;
	}

	return node;
}

ASTNodePtr Parser::parseFactor() {
	Token t = peek();

	if (t.type == TokenType::NUMBER) {
		consume(TokenType::NUMBER);
		auto node = std::make_shared<ASTNode>(NodeType::Number);
		node->value = t.lexeme;
		return node;
	}
	if (t.type == TokenType::IDENT) {
		consume(TokenType::IDENT);
		auto node = std::make_shared<ASTNode>(NodeType::Variable);
		node->value = t.lexeme;
		return node;
	}
	if (t.type == TokenType::LPAREN) {
		consume(TokenType::LPAREN);
		auto node = parseExpression();
		consume(TokenType::RPAREN);
		return node;
	}

	throw std::runtime_error("Unexpected token in factor");
}

ASTNodePtr Parser::parseTerm() {
	auto node = parseFactor();

	while (peek().type == TokenType::STAR || peek().type == TokenType::SLASH) {
		Token op = consume(peek().type);
		auto right = parseFactor();
		auto bin = std::make_shared<ASTNode>(NodeType::BinaryOp);
		bin->op = op.lexeme;
		bin->left = node;
		bin->right = right;
		node = bin;
	}

	return node;
}
