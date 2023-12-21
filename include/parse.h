#ifndef PARSE_H
#define PARSE_H

#include "ast.h"
#include "token.h"

extern typedef struct ast_node;

void parse_ast(ast_node *head, token_node *head);

#endif
