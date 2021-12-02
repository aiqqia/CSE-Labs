#ifndef __RDCONSTANTS_H__
#define __RDCONSTANTS_H__
enum NON_TERMINALS
{ // types for non terminals.
	PROGRAM,
	DECLARATIONS,
	DATA_TYPE,
	IDENTIFIERLIST,
	IDENTIFIERLISTPRIME,
	IDENTIFIERLISTPRIMEPRIME,
	STATEMENT_LIST,
	STATEMENT,
	ASSIGN_STAT,
	EXPN,
	EPRIME,
	SIMPLE_EXP,
	SEPRIME,
	TERM,
	TPRIME,
	FACTOR,
	DECISION,
	DPRIME,
	LOOPING,
	RELOP,
	ADDOP,
	MULOP
};

// ToDo: calculate the first and follow of the grammar

char first[][6][20] = {
	{"int"},
	{"int", "char", "double", "float"},
	{"int", "char", "double", "float"},
	{"id"},
	{",", "["},
	{","},
	{"id", "if", "while", "for"},
	{"id", "if", "while", "for"},
	{"id"},
	{"id", "num"},
	{"==", "!=", ">=", "<=", ">", "<"},
	{"id", "num"},
	{"+", "-"},
	{"id", "num"},
	{"*", "/", "%"},
	{"id", "num"},
	{"if"},
	{"else"},
	{"while", "for"},
	{"==", "!=", ">=", "<=", ">", "<"},
	{"+", "-"},
	{"*", "/", "%"},
};
char follow[][15][20] = {
	{"$"},
	{"return", "}", "id", "if", "while", "for"},
	{"id"},
	{";"},
	{";"},
	{";"},
	{"}"},
	{"id", "if", "while", "for", "}"},
	{";", ")"},
	{";", ")", "==", "!=", ">=", "<=", ">", "<"},
	{";", ")", "==", "!=", ">=", "<=", ">", "<"},
	{";", ")", "==", "!=", ">=", "<=", ">", "<", "id", "num"},
	{";", ")", "==", "!=", ">=", "<=", ">", "<", "id", "num"},
	{"+", "-", ";", ")", "==", "!=", ">=", "<=", ">", "<", "id", "num"},
	{"+", "-", ";", ")", "==", "!=", ">=", "<=", ">", "<", "id", "num"},
	{"*", "/", "%", "+", "-", ";", ")", "==", "!=", ">=", "<=", ">", "<", "id", "num"},
	{"id", "if", "while", "for", "}"},
	{"id", "if", "while", "for", "}"},
	{"id", "if", "while", "for", "}"},
	{"id", "num"},
	{"id", "num"},
	{"id", "num"}};

int firstSz[] = {1, 4, 4, 1, 2, 1, 4, 4, 1, 2, 6, 2, 2, 2, 3, 2, 1, 1, 2, 6, 2, 3};
int followSz[] = {1, 6, 1, 1, 1, 1, 1, 5, 2, 8, 8, 10, 10, 12, 12, 15, 5, 5, 5, 2, 2, 2};
#endif