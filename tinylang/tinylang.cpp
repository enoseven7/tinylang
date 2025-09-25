#include <iostream>
#include <vector>
#include "lexer.h"

extern std::vector<Token> tokenize(const std::string& source);

int main() {
	std::string code = "let x = 5; print (x + 2)";
	auto tokens = tokenize(code);

	for (auto& t : tokens) {
		std::cout << "Token(" << (int)t.type << ", \"" << t.lexeme << "\")\n";
	}
	return 0;
}