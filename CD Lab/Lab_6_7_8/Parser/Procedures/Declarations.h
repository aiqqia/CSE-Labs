#ifndef __DECLARATIONS_H__
#define __DECLARATIONS_H__
void Declarations()
{
	get();
	prev_flag = true;
	if (search_first(DATA_TYPE, tkn->lexeme, tkn->type) == 1)
	{
		DataType();
		get();
		if (search_first(IDENTIFIERLIST, tkn->lexeme, tkn->type) == 1)
		{
			prev_flag = true;
			Identifier();
			get();
			if (strcmp(tkn->lexeme, ";") == 0)
			{
				get();
				prev_flag = true;
				if (search_first(DECLARATIONS, tkn->lexeme, tkn->type) == 1)
				{
					Declarations();
				}
				else if (search_follow(DECLARATIONS, tkn->lexeme, tkn->type) == 0)
				{
					failure("Invalid Identifier : Declaration.");
				}
			}
			else
			{
				failure("Semi Colon Expected! : Declaration.");
			}
		}
		else
		{
			failure("Identifier expected! : Declaration.");
		}
	}
}
#endif