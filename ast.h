#ifndef AST_H
#define AST_H

typedef struct ast_node;
typedef struct ast_node_list;

typedef struct {
	ast_node *parent;
	ast_node_list *children;
	char *morpheme;
	char *token;
} ast_node;

typedef struct {
	ast_node *node;
	ast_node *next;
} ast_node_list;

ast_node* init_ast(char *morpheme, char *token); //call _alloc_ast_tree()
ast_node* free_ast(ast_node *head); //call _free_ast_tree()
void free_ast_node_list(ast_node_list *head);
void init_ast_node_list(ast_node *node);
void add_ast_node_to_list(); //call _extend_ast_list()
void branch_at_node(); //call _branch_at_node();
void rise_level() //call _rise_level();
void recurse_ast(); //call _find_bottom_left();
void update_ast_node(); //check for non-null cases!! use this to init AND replace ast node data
		//if linkages aren't null, unlink+free the old linkages then add the new linkages

#endif


