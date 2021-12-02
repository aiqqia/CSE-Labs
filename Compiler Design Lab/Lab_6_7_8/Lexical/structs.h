#ifndef __STRUCTS_H__
#define __STRUCTS_H__

struct node
{
	char *cur;
	int row, col;
	struct node *next;
	enum TYPE type;
}; // element for hash table

struct symbol
{
	char *name;
	char *data_type;
	struct symbol *next;
	unsigned int size, row, col;
}; // element for symbol table

struct token
{
	char *lexeme;
	enum TYPE type;
	int row, col;
}; // token returned by getNextToken()

#endif