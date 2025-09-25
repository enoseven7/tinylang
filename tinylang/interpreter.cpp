#include "interpreter.h"
#include <iostream>
#include <stdexcept>

// Variable storage
std::unordered_map<std::string, int> variables;

int evaluate(ASTNodePtr node) {
	switch (node->type) {
		case NodeType::Number:
			return std::stoi(node->value);

		case NodeType::Variable:
			if (variables.count(node->value) == 0)
				throw std::runtime_error("Undefined variable: " + node->value);
			return variables[node->value];

		case NodeType::BinaryOp: {
			int left = evaluate(node->left);
			int right = evaluate(node->right);
			if (node->op == "+") return left + right;
			if (node->op == "-") return left - right;
			if (node->op == "*") return left * right;
			if (node->op == "/") return left / right;
			throw std::runtime_error("Unknown operator: " + node->op);
		}

		default:
			throw std::runtime_error("Unknown AST node type");
	}
}

void execute(ASTNodePtr program) {
	for (auto& stmt : program->children) {
		switch (stmt->type) {
			case NodeType::Assignment: {
				int value = evaluate(stmt->left);
				variables[stmt->value] = value;
				break;
			}
			case NodeType::Print: {
				int value = evaluate(stmt->left);
				std::cout << value << "\n";
				break;
			}
			default:
				throw std::runtime_error("Unknown statement type");

		}
	}
}