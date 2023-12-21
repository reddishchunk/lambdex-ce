#ifndef TOKEN_H
#define TOKEN_H
	
typedef struct token_node;
typedef struct {
	char *morpheme;
	char *token;
	token_node *next;
} token_node;

token_node* init_token_list(char *morpheme); //call _alloc_token_list()
token_node* free_token_list(token_node *head); //call _free_token_list()
void add_morpheme_token_node(char *morpheme, *token); //call _add_token_node() (END!!)

#endif
