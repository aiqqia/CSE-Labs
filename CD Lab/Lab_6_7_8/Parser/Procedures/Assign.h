#ifndef __ASSIGN_H__
#define __ASSIGN_H__
void AssignStat()
{
	get();
	if (search_symbol(tkn->lexeme) != -1)
	{
		get();
		if (strcmp(tkn->lexeme, "=") == 0)
		{
			get();
			prev_flag = true;
			if (search_first(EXPN, tkn->lexeme, tkn->type) == 1)
				Expn();
			else
				failure("Invalid Identifier or number : Assign.");
		}
		else
		{
			failure("= sign not found! : Assign.");
		}
	}
	else
	{
		failure("Invalid Identifier! : Assign.");
	}
}

#endif