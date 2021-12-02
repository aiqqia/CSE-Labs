#ifndef __DECISION_H__
#define __DECISION_H__

void Decision()
{
	get();
	if (strcmp(tkn->lexeme, "if") == 0)
	{
		get();
		if (strcmp(tkn->lexeme, "(") == 0)
		{
			get();
			prev_flag = true;
			if (search_first(EXPN, tkn->lexeme, tkn->type) == 1)
			{
				Expn();
				get();
				if (strcmp(tkn->lexeme, ")") == 0)
				{
					get();
					if (strcmp(tkn->lexeme, "{") == 0)
					{
						get();
						prev_flag = true;
						if (search_first(STATEMENT_LIST, tkn->lexeme, tkn->type) == 1)
						{
							Statement_List();
							get();
							if (strcmp(tkn->lexeme, "}") == 0)
							{
								get();
								prev_flag = true;
								if (search_first(DPRIME, tkn->lexeme, tkn->type) == 1)
								{
									DPrime();
								}
							}
							else
								failure("} expected! : Decision.");
						}
					}
					else
						failure("{ expected! : Decision.");
				}
				else
					failure(") expected! Decision.");
			}
			else
			{
				failure("Invalid Expression. : Decision.");
			}
		}
		else
			failure("( expected! : Decision.");
	}
	else
		failure("No decision statement found! : Decision.");
}

void DPrime()
{
	get();
	if (strcmp(tkn->lexeme, "else") == 0)
	{
		get();
		if (strcmp(tkn->lexeme, "{") == 0)
		{
			get();
			prev_flag = true;
			if (search_first(STATEMENT_LIST, tkn->lexeme, tkn->type) == 1)
			{
				Statement_List();
				get();
				if (strcmp(tkn->lexeme, "}") != 0)
				{
					failure("} expected! : DPrime.");
				}
			}
			else
			{
				failure("Invalid Statement! : DPrime.");
			}
		}
		else
			failure("{ expected! : DPrime.");
	}
	else
	{
		prev_flag = true;
	}
}

#endif