#include "lexer.h"
#include <vector>
#include <stdexcept>
#include <cctype>

std::vector<Token> tokenize(const std::string& source) {
	std::vector<Token> tokens;
	size_t i = 0;

	while (i < source.size()) {
		char c = source[i];

		//skipping spaces

		if (isspace(c)) {
			i++;
			continue;
		}

		//numbers first of all

		if (isdigit(c)) {
			std::string num;
			while (i < source.size() && isdigit(source[i])) {
				num += source[i++];
			}
			tokens.push_back({ TokenType::NUMBER, num });
			continue;
		}

		//keywords

		if (isalpha(c)) {
			std::string ident;
			while (i < source.size() && isalpha(source[i])) {
				ident += source[i++];
			}
			if (ident == "let")
				tokens.push_back({ TokenType::LET, ident });
			else if (ident == "print")
				tokens.push_back({ TokenType::PRINT, ident });
			else
				tokens.push_back({ TokenType::IDENT, ident });
			continue;
		}

		//single character

		switch (c) {
			case '=': tokens.push_back({ TokenType::EQUAL, "=" }); break;
			case ';': tokens.push_back({ TokenType::SEMICOLON, ";" }); break;
			case '+': tokens.push_back({TokenType::PLUS, "+"}); break;
			case '-': tokens.push_back({TokenType::MINUS, "-"}); break;
			case '*': tokens.push_back({TokenType::STAR, "*"}); break;
			case '/': tokens.push_back({TokenType::SLASH, "/"}); break;
			case '(': tokens.push_back({TokenType::LPAREN, "("}); break;
			case ')': tokens.push_back({TokenType::RPAREN, ")"}); break;

			//incase of unexpected character
			default: throw std::runtime_error(std::string("Unexpected character: ") + c);
		}

		i++;
	}

	tokens.push_back({ TokenType::END_OF_FILE, "" });
	return tokens;
}