#ifndef __GETNEXTTOKEN_H__
#define __GETNEXTTOKEN_H__
Token getNextToken(FILE *finp, int *row_pointer, int *col_pointer, char data_type_buffer[], char *c)
{
	char buffer[100];
	int i = 0, col;
	Token tkn = NULL;
	if (isalpha(*c) != 0 || *c == '_')
	{
		buffer[i++] = *c;
		col = (*col_pointer);
		while (isalpha(*c) != 0 || *c == '_' || isdigit(*c) != 0)
		{
			*c = fgetc(finp);
			(*col_pointer)++;
			if (isalpha(*c) != 0 || *c == '_' || isdigit(*c) != 0)
				buffer[i++] = *c;
		}
		buffer[i] = '\0';
		if (isdatatype(buffer) == 1)
		{
			strcpy(data_type_buffer, buffer);
			tkn = insert(buffer, (*row_pointer), col - 1, KEYWORD); // data type
		}
		else if (iskeyword(buffer) == 1)
		{
			tkn = insert(buffer, (*row_pointer), col - 1, KEYWORD); // keyword
		}
		else
		{
			tkn = insert(buffer, (*row_pointer), col - 1, IDENTIFIER); // identifier
			if (*c == '(')
				insert_symbol(buffer, "function", *row_pointer, col - 1);
			else
				insert_symbol(buffer, data_type_buffer, *row_pointer, col - 1);
			// data_type_buffer[0] = '\0';
		}
		i = 0;
		if (*c == '\n')
			(*row_pointer)++, (*col_pointer) = 1;
		buffer[0] = '\0';
	}
	else if (isdigit(*c) != 0)
	{
		buffer[i++] = *c;
		col = (*col_pointer);
		while (isdigit(*c) != 0 || *c == '.')
		{
			*c = fgetc(finp);
			(*col_pointer)++;
			if (isdigit(*c) != 0 || *c == '.')
				buffer[i++] = *c;
		}
		buffer[i] = '\0';
		tkn = insert(buffer, (*row_pointer), col - 1, NUMERIC_CONSTANT); // numerical constant
		i = 0;
		if (*c == '\n')
			(*row_pointer)++, (*col_pointer) = 1;
		buffer[0] = '\0';
	}
	else if (*c == '\"')
	{
		col = (*col_pointer);
		buffer[i++] = *c;
		*c = 0;
		while (*c != '\"')
		{
			*c = fgetc(finp);
			(*col_pointer)++;
			buffer[i++] = *c;
		}
		buffer[i] = '\0';
		tkn = insert(buffer, (*row_pointer), col - 1, STRING_LITERAL); // string literals
		buffer[0] = '\0';
		i = 0;
		*c = fgetc(finp);
		(*col_pointer)++;
	}
	else if (*c == '\'')
	{
		col = (*col_pointer);
		buffer[i++] = *c;
		*c = 0;
		*c = fgetc(finp);
		(*col_pointer)++;
		buffer[i++] = *c;
		if (*c == '\\')
		{
			*c = fgetc(finp);
			(*col_pointer)++;
			buffer[i++] = *c;
		}
		*c = fgetc(finp);
		(*col_pointer)++;
		buffer[i++] = *c;
		buffer[i] = '\0';
		tkn = insert(buffer, (*row_pointer), col - 1, CHARACTER_CONSTANT); // character constants
		buffer[0] = '\0';
		i = 0;
		*c = fgetc(finp);
		(*col_pointer)++;
	}
	else
	{
		col = (*col_pointer);
		if (*c == '=')
		{ // relational and logical operators
			*c = fgetc(finp);
			(*col_pointer)++;
			if (*c == '=')
			{
				tkn = insert("==", (*row_pointer), col - 1, RELATIONAL_OPERATOR);
			}
			else
			{
				tkn = insert("=", (*row_pointer), col - 1, RELATIONAL_OPERATOR);
				fseek(finp, -1, SEEK_CUR);
				(*col_pointer)--;
			}
		}
		else if (*c == '>' || *c == '<' || *c == '!')
		{
			char temp = *c;
			*c = fgetc(finp);
			(*col_pointer)++;
			if (*c == '=')
			{
				char temp_str[3] = {
					temp,
					'=',
					'\0'};
				tkn = insert(temp_str, (*row_pointer), col - 1, RELATIONAL_OPERATOR);
			}
			else
			{
				char temp_str[2] = {
					temp,
					'\0'};
				tkn = insert(temp_str, (*row_pointer), col - 1, RELATIONAL_OPERATOR);
				fseek(finp, -1, SEEK_CUR);
				(*col_pointer)--;
			}
		}
		else if (isbracket(*c) == 1)
		{ // parentheses and special symbols
			char temp_string[2] = {
				*c,
				'\0'};
			tkn = insert(temp_string, (*row_pointer), col - 1, BRACKET);
		}
		else if (isspecial(*c) == 1)
		{ // parentheses and special symbols
			char temp_string[2] = {
				*c,
				'\0'};
			tkn = insert(temp_string, (*row_pointer), col - 1, SPECIAL_SYMBOL);
		}
		else if (isoperator(*c) == 1)
		{ // operators
			char temp = *c;
			*c = fgetc(finp);
			(*col_pointer)++;
			if (*c == '=' || (temp == '+' && *c == '+') || (temp == '-' && *c == '-'))
			{
				char temp_string[3] = {
					temp,
					*c,
					'\0'};
				tkn = insert(temp_string, (*row_pointer), col - 1, OPERATOR);
			}
			else
			{
				char temp_String[2] = {
					temp,
					'\0'};
				tkn = insert(temp_String, (*row_pointer), col - 1, OPERATOR);
				fseek(finp, -1, SEEK_CUR);
				(*col_pointer)--;
			}
		}
		else if (*c == '\n') // new line
			(*row_pointer)++, (*col_pointer) = 1;
		else if (*c == '$')
		{
			Token eof = (Token)malloc(sizeof(struct token));
			eof->lexeme = "EOF";
			return eof;
		}
		*c = fgetc(finp);
		(*col_pointer)++;
	}
	return tkn;
}
#endif