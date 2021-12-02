#ifndef __UTILS_H__
#define __UTILS_H__
int iskeyword(char buffer[]) // function to check for keyword
{
	for (int i = 0; i < 34; i++)
	{
		if (strcmp(buffer, keywords[i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}

int isdatatype(char buffer[])
{ // function to check for data_Type
	for (int i = 0; i < 4; i++)
	{
		if (strcmp(buffer, data_types[i]) == 0)
			return 1;
	}
	return 0;
}

int isoperator(char c)
{ // function to check for operator
	for (int i = 0; i < 5; i++)
	{
		if (operators[i] == c)
			return 1;
	}
	return 0;
}

int isspecial(char c)
{ // function to check for special symbol
	for (int i = 0; i < 12; i++)
	{
		if (special_symbols[i] == c)
			return 1;
	}
	return 0;
}

int isbracket(char c)
{ // function to check for bracket
	for (int i = 0; i < 6; i++)
	{
		if (brackets[i] == c)
			return 1;
	}
	return 0;
}
#endif