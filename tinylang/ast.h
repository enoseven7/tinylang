#pragma once
#include <string>
#include <memory>
#include <vector>

enum class NodeType {
	Program,
	Assignment,
	Print,
	BinaryOp,
	Number,
	Variable
};

struct ASTNode;

using ASTNodePtr = std::shared_ptr<ASTNode>;

struct ASTNode {
	NodeType type;

	std::string value; // For Number and Variable nodes

	//For binary operations

	std::string op;
	ASTNodePtr left;
	ASTNodePtr right;

	//For program and statements
	std::vector<ASTNodePtr> children;

	ASTNode(NodeType t) : type(t) {}
};