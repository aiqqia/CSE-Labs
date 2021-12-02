#ifndef __HASH_H__
#define __HASH_H__
int hash(int size) // hashing function
{
	return (size) % MAX_SIZE;
}

void display_st() // display the symbol table
{
	printf("      Name    |      Type    |      Size     |     Row     |     Col     \n");
	printf("-------------------------------------------------------------------------\n");
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (st[i] == NULL)
			continue;
		else
		{
			Symbol cur = st[i];
			while (cur)
			{
				printf("%10s    |%10s    |%10d    |%10d    |%10d    \n", cur->name, cur->data_type, cur->size, cur->row, cur->col);
				cur = cur->next;
			}
		}
	}
}

int search_symbol(char identifier[]) // to search in symbol_table
{
	int index = hash(strlen(identifier));
	if (st[index] == NULL)
		return -1;
	Symbol cur = st[index];
	int i = 0;
	while (cur != NULL)
	{
		if (strcmp(identifier, cur->name) == 0)
			return i;
		cur = cur->next;
		i++;
	}
	return -1;
}

int search(char buffer[], enum TYPE type) // to search in hash table
{
	int index = hash(strlen(buffer));
	if (hashTable[index] == NULL)
		return 0;
	Node cur = hashTable[index];
	while (cur != NULL)
	{
		if (strcmp(cur->cur, buffer) == 0)
			return 1;
		cur = cur->next;
	}
	return 0;
}

void insert_symbol(char identifier[], char data_type[], int row, int col)
{ // insert in symbol table
	if (search_symbol(identifier) == -1)
	{
		Symbol n = (Symbol)malloc(sizeof(struct symbol));
		char *str = (char *)calloc(strlen(identifier) + 1, sizeof(char));
		strcpy(str, identifier);
		n->name = str;
		n->next = NULL;
		n->row = row;
		n->col = col;
		char *typee = (char *)calloc(strlen(data_type) + 1, sizeof(char));
		strcpy(typee, data_type);
		n->data_type = typee;
		if (strcmp(data_type, "int") == 0)
			n->size = 4;
		else if (strcmp(data_type, "double") == 0)
			n->size = 8;
		else if (strcmp(data_type, "char") == 0)
			n->size = 1;
		else if (strcmp(data_type, "function") == 0)
			n->size = 0;
		else
			n->size = 4;
		int index = hash(strlen(identifier));
		//
		if (st[index] == NULL)
		{
			st[index] = n;
			return;
		}
		Symbol cur = st[index];
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = n;
	}
}

Token insert(char buffer[], int row, int col, enum TYPE type)
{ // insert in hash table
	Token tkn = (Token)malloc(sizeof(struct token));
	char *lexeme = (char *)calloc(strlen(buffer) + 1, sizeof(char));
	strcpy(lexeme, buffer);
	tkn->lexeme = lexeme;
	tkn->type = type;
	tkn->col = col;
	tkn->row = row;
	if (type == IDENTIFIER || search(buffer, type) == 0)
	{
		// printf("< %s | %d | %d | %s >\n", buffer, row, col, types[type]);
		int index = hash(strlen(buffer));
		Node n = (Node)malloc(sizeof(struct node));
		char *str = (char *)calloc(strlen(buffer) + 1, sizeof(char));
		strcpy(str, buffer);
		n->cur = str;
		n->next = NULL;
		n->row = row;
		n->col = col;
		n->type = type;
		if (hashTable[index] == NULL)
		{
			hashTable[index] = n;
			return tkn;
		}
		Node cur = hashTable[index];
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = n;
	}
	return tkn;
}
#endif