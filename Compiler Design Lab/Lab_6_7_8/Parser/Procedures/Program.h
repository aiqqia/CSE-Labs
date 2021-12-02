#ifndef __PROGRAM_H__
#define __PROGRAM_H__

void Program()
{
	get();
	if (strcmp(tkn->lexeme, "int") == 0)
	{
		get();
		if (strcmp(tkn->lexeme, "main") == 0)
		{
			get();
			if (strcmp(tkn->lexeme, "(") == 0)
			{
				get();
				if (strcmp(tkn->lexeme, ")") == 0)
				{
					get();
					if (strcmp(tkn->lexeme, "{") == 0)
					{
						get();
						if (search_first(DECLARATIONS, tkn->lexeme, tkn->type) == 1)
						{
							prev_flag = true;
							Declarations();
							get();
							if (search_first(STATEMENT_LIST, tkn->lexeme, tkn->type) == 1)
							{
								prev_flag = true;
								Statement_List();
								get();
								if (strcmp(tkn->lexeme, "return") == 0)
								{
									get();
									if (tkn->type == NUMERIC_CONSTANT)
									{
										get();
										if (strcmp(tkn->lexeme, ";") == 0)
										{
											get();
											if (strcmp(tkn->lexeme, "}") == 0)
											{
												success();
											}
											else
											{
												failure("No closing curly braces found! : Program.");
											}
										}
										else
										{
											failure("No Semi-Colon found! : Program.");
										}
									}
									else
									{
										failure("Numeric Value Expected! : Program.");
									}
								}
								else
								{
									failure("No return statement found! : Program.");
								}
							}
							else
							{
								failure("Invalid Identifier! : Program.");
							}
						}
						else
						{
							failure("Data Type expected! : Program.");
						}
					}
					else
					{
						failure("No starting curly bracket found! : Program.");
					}
				}
				else
				{
					failure("No function closing parentheses found! : Program.");
				}
			}
			else
			{
				failure("No function starting parentheses found! : Program.");
			}
		}
		else
		{
			failure("No main found! : Program.");
		}
	}
	else
	{
		failure("No return type found! : Program.");
	}
}

#endif