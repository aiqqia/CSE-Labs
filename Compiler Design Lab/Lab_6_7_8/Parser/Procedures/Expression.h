#ifndef __EXPRESSION_H__
#define __EXPRESSION_H__
void Expn()
{
	if (search_first(SIMPLE_EXP, tkn->lexeme, tkn->type) == 1)
	{
		Simple_Exp();
		if (search_first(EPRIME, tkn->lexeme, tkn->type) == 1)
			EPrime();
	}
	else
	{
		failure("Invalid Identifier or Number! : Expn.");
	}
}

void EPrime()
{
	if (search_first(RELOP, tkn->lexeme, tkn->type) == 1)
	{
		Relop();
		get();
		prev_flag = true;
		if (search_first(SIMPLE_EXP, tkn->lexeme, tkn->type) == 1)
			Simple_Exp();
		else
			failure("Invalid Identifier or Number! : EPrime.");
	}
	else if (search_follow(EPRIME, tkn->lexeme, tkn->type) != 1)
	{
		failure("Invalid Operator or ; expected! : EPrime.");
	}
}

void Simple_Exp()
{
	if (search_first(TERM, tkn->lexeme, tkn->type) == 1)
	{
		Term();
		if (search_first(SEPRIME, tkn->lexeme, tkn->type) == 1)
			SePrime();
	}
	else
	{
		failure("Invalid Identifier or number! : Simple Exp.");
	}
}

void SePrime()
{
	if (search_first(ADDOP, tkn->lexeme, tkn->type) == 1)
	{

		Addop();
		get();
		prev_flag = true;
		if (search_first(TERM, tkn->lexeme, tkn->type) == 1)
		{
			Term();
			if (search_first(SEPRIME, tkn->lexeme, tkn->type) == 1)
				SePrime();
		}
		else
			failure("Invalid Identifier or number! : SePrime.");
	}
	else if (search_follow(SEPRIME, tkn->lexeme, tkn->type) != 1)
	{
		failure("Invalid Operator! : SePrime.");
	}
}

void Term()
{
	if (search_first(FACTOR, tkn->lexeme, tkn->type) == 1)
	{
		Factor();
		get();
		prev_flag = true;
		if (search_first(TPRIME, tkn->lexeme, tkn->type) == 1)
		{
			TPrime();
		}
	}
	else
	{
		failure("Invalid Identifier or number! : Term.");
	}
}

void TPrime()
{
	if (search_first(MULOP, tkn->lexeme, tkn->type) == 1)
	{
		Mulop();
		get();
		prev_flag = true;
		if (search_first(FACTOR, tkn->lexeme, tkn->type) == 1)
		{
			Factor();
			get();
			prev_flag = true;
			if (search_first(TPRIME, tkn->lexeme, tkn->type) == 1)
			{
				TPrime();
			}
		}
		else
		{
			failure("Invalid Identifier! : TPrime.");
		}
	}
	else if (search_follow(TPRIME, tkn->lexeme, tkn->type) != 1)
	{
		failure("Invalid Operator! : TPrime.");
	}
}

void Factor()
{
	get();
	if (search_symbol(tkn->lexeme) == -1 && tkn->type != NUMERIC_CONSTANT)
	{
		failure("Invalid Identifier or Number : Factor.");
	}
}

#endif