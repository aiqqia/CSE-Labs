#ifndef __RDUTILS_H__
#define __RDUTILS_H__

int row, col_global;
char data_type_buffer[100], c = 0;
FILE *finp;
Token tkn = NULL;
int prev_flag = false;

int search_first(enum NON_TERMINALS val, char *buffer, enum TYPE type)
{
	if (type == IDENTIFIER)
	{
		return search_symbol(buffer) != -1 && search_first(val, "id", KEYWORD);
	}
	if (type == NUMERIC_CONSTANT)
	{
		return search_first(val, "num", KEYWORD);
	}
	for (int i = 0; i < firstSz[val]; i++)
	{
		if (strcmp(buffer, first[val][i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}

int search_follow(enum NON_TERMINALS val, char *buffer, enum TYPE type)
{
	if (type == IDENTIFIER)
	{
		return search_follow(val, "id", KEYWORD) && search_symbol(buffer) != -1;
	}
	if (type == NUMERIC_CONSTANT)
	{
		return search_follow(val, "num", KEYWORD);
	}
	for (int i = 0; i < followSz[val]; i++)
	{
		if (strcmp(buffer, follow[val][i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}

void failure(char *msg)
{
	printf("\n ### Given File is NOT Accepted!! ###\nError : %s at\n Row : %d, Col : %d\n", msg, tkn->row, tkn->col);
	exit(0);
}

void success()
{
	printf("\n**** Given File is Accepted!! ****\n");
}

#endif