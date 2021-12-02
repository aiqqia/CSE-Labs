#ifndef __LOOPING_H__
#define __LOOPING_H__

void Looping()
{
	get();
	if (strcmp(tkn->lexeme, "while") == 0)
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
				if (strcmp(tkn->lexeme, ")") != 0)
				{
					failure(") expected! : W Looping.");
				}
				get();
				if (strcmp(tkn->lexeme, "{") == 0)
				{
					get();
					prev_flag = true;
					// if (search_first(STATEMENT_LIST, tkn->lexeme, tkn->type) == 1)
					{
						Statement_List();
						get();
						if (strcmp(tkn->lexeme, "}") != 0)
						{
							failure("} expected! : W Looping.");
						}
					}
					// else printf("%s\n", tkn->lexeme), failure("Invalid statement! : Looping.");
				}
				else
					failure("{ expected! : W Looping");
			}
			else
				failure("Invalid Expression. : W Looping.");
		}
		else
			failure("( expected! : W Looping");
	}
	else if (strcmp(tkn->lexeme, "for") == 0)
	{
		get();
		if (strcmp(tkn->lexeme, "(") == 0)
		{
			get();
			prev_flag = true;
			if (search_first(ASSIGN_STAT, tkn->lexeme, tkn->type) == 1)
			{
				AssignStat();
				get();
				if (strcmp(tkn->lexeme, ";") == 0)
				{
					get();
					prev_flag = true;
					if (search_first(EXPN, tkn->lexeme, tkn->type) == 1)
					{
						Expn();
						get();
						if (strcmp(tkn->lexeme, ";") == 0)
						{
							get();
							prev_flag = true;
							if (search_first(ASSIGN_STAT, tkn->lexeme, tkn->type) == 1)
							{
								AssignStat();
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
											if (strcmp(tkn->lexeme, "}") != 0)
											{
												failure("} expected! : F Looping");
											}
										}
										else
											failure("Invalid Identifier! : F Looping");
									}
									else
									{
										failure("{ expected! : F Looping");
									}
								}
								else
									failure(") expected : F Looping");
							}
							else
								failure("Invalid Identifier! : F Looping");
						}
						else
							failure("; expected! : F Looping");
					}
					else
						failure("Invalid Expression! : F Looping");
				}
				else
					failure("; expected! : F Looping");
			}
			else
				failure("Invalid Identifier! : F Looping");
		}
		else
			failure("( expected! : F Looping");
	}
	else
		failure("Invalid Loop! : F Looping");
}

#endif