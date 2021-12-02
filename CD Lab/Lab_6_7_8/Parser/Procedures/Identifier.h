#ifndef __IDENTIFIER_H__
#define __IDENTIFIER_H__
void Identifier()
{
	get();
	if (search_symbol(tkn->lexeme) != -1)
	{
		get();
		prev_flag = true;
		if (search_first(IDENTIFIERLISTPRIME, tkn->lexeme, tkn->type) == 1)
		{
			IdentifierPrime();
		}
		else if (search_follow(IDENTIFIERLIST, tkn->lexeme, tkn->type) != 1)
		{
			failure("; expected! : Identifier.");
		}
	}
	else
	{
		failure("Invalid Identifier! : Identifier.");
	}
}

void IdentifierPrime()
{
	get();
	if (strcmp(tkn->lexeme, ",") == 0)
	{
		get();
		if (search_first(IDENTIFIERLIST, tkn->lexeme, tkn->type) == 1)
		{
			prev_flag = true;
			Identifier();
		}
		else if (strcmp(tkn->lexeme, "[") == 0)
		{
		}
		else
		{
			failure("Invalid Identifier! : Identifier`.");
		}
	}
	else if (strcmp(tkn->lexeme, "[") == 0)
	{
		get();
		if (tkn->type == NUMERIC_CONSTANT)
		{
			get();
			if (strcmp(tkn->lexeme, "]") == 0)
			{
				if (search_first(IDENTIFIERLISTPRIMEPRIME, tkn->lexeme, tkn->type) == 1)
					IdentifierPrimePrime();
			}
			else
			{
				failure("] expected!  : Identifier`.");
			}
		}
		else
		{
			failure("Number expected!  : Identifier`.");
		}
	}
	else
	{
		if (search_follow(IDENTIFIERLISTPRIME, tkn->lexeme, tkn->type) == 1)
			prev_flag = true;
		else
		{
			failure("; expected!  : Identifier`.");
		}
	}
}

void IdentifierPrimePrime()
{
	get();
	if (strcmp(tkn->lexeme, ",") == 0)
	{
		if (search_first(IDENTIFIERLIST, tkn->lexeme, tkn->type) == 1)
			Identifier();
		else
		{
			failure("Invalid Identifier!  : Identifier``.");
		}
	}
	else
	{
		if (search_follow(IDENTIFIERLISTPRIMEPRIME, tkn->lexeme, tkn->type) == 1)
			prev_flag = true;
		else
		{
			failure("; expected!  : Identifier``.");
		}
	}
}
#endif