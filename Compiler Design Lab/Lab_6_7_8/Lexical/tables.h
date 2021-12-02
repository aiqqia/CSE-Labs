#ifndef __TABLES_H__
#define __TABLES_H__
#define MAX_SIZE 20
typedef struct node *Node;
typedef struct symbol *Symbol;
typedef struct token *Token;
Node hashTable[MAX_SIZE]; // hash table
Symbol st[MAX_SIZE];	  // symbol table
#endif