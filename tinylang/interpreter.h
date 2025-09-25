#pragma once
#include "ast.h"
#include <unordered_map>
#include <string>

extern std::unordered_map<std::string, int> variables;

int evaluate(ASTNodePtr node);
void execute(ASTNodePtr program);