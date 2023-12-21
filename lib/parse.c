#include "parse.h"
#include "ast.h"
#include "token.h"

void parse_ast(ast_node *an_head, token_node *tn_head) {
	ast_node *curr_an = an_head;
	token_node *curr_tn, *next_tn;
	tn = tn_head;
	tn_next = tn->next;
	
	while (curr_tn != NULL) {
		
		if (strcmp(curr_tn->token, "lparen") 
			|| strcmp(curr_tn->token, "\\" 
			|| strcmp(curr_tn->token, "\t")) {
			curr_an = branch(curr_an);
			update_ast_node(curr_an, curr_tn->morpheme, curr_tn->token);
		
		curr_tn = curr_tn->next;
		curr_tn_next = curr_tn->next->next;

