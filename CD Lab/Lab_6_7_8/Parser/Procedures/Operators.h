#ifndef __OPERATORS_H__
#define __OPERATORS_H__
void Relop()
{
	get();
	if (strcmp(tkn->lexeme, "==") == 0 || strcmp(tkn->lexeme, "!=") == 0 || strcmp(tkn->lexeme, ">=") == 0 || strcmp(tkn->lexeme, "<=") == 0 || strcmp(tkn->lexeme, ">") == 0 || strcmp(tkn->lexeme, "<") == 0)
	{
		return;
	}
	else
	{
		failure("Invalid Operator! : Operators.");
	}
}

void Addop()
{
	get();
	if (strcmp(tkn->lexeme, "+") == 0 || strcmp(tkn->lexeme, "-") == 0)
	{
		return;
	}
	else
	{
		failure("Invalid Operator! : Operators.");
	}
}

void Mulop()
{
	get();
	if (strcmp(tkn->lexeme, "*") == 0 || strcmp(tkn->lexeme, "/") == 0 || strcmp(tkn->lexeme, "%%") == 0)
	{
		return;
	}
	else
	{
		failure("Invalid Operator! : Operators.");
	}
}
#endif