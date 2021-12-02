#ifndef __STATEMENT_H__
#define __STATEMENT_H__
void Statement_List()
{
	get();
	prev_flag = true;
	if (search_first(STATEMENT, tkn->lexeme, tkn->type) == 1)
	{
		Statement();
		get();
		prev_flag = true;
		if (search_first(STATEMENT_LIST, tkn->lexeme, tkn->type) == 1)
		{
			Statement_List();
		}
	}
	else if (search_follow(STATEMENT_LIST, tkn->lexeme, tkn->type) != 1)
	{
		failure("Invalid Statement! : Statement List.");
	}
}

void Statement()
{
	get();
	prev_flag = true;
	if (search_first(ASSIGN_STAT, tkn->lexeme, tkn->type) == 1)
	{
		AssignStat();
		get();
		if (strcmp(tkn->lexeme, ";") != 0)
		{
			failure("; expected! : Statement.");
		}
	}
	else if (search_first(DECISION, tkn->lexeme, tkn->type) == 1)
	{
		Decision();
	}
	else if (search_first(LOOPING, tkn->lexeme, tkn->type) == 1)
	{
		Looping();
	}
	else if (search_follow(STATEMENT, tkn->lexeme, tkn->type) != 1)
	{
		failure("Invalid Statement! : Statement.");
	}
}
#endif