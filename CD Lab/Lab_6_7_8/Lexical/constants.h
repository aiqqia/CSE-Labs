#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

char keywords[34][10] = {
	"true",
	"false",
	"auto",
	"double",
	"int",
	"struct",
	"break",
	"else",
	"long",
	"switch",
	"case",
	"enum",
	"register",
	"typedef",
	"char",
	"extern",
	"return",
	"union",
	"const",
	"float",
	"short",
	"unsigned",
	"continue",
	"for",
	"signed",
	"void",
	"default",
	"goto",
	"sizeof",
	"voltile",
	"do",
	"if",
	"static",
	"while"};			  // list of keywords
char data_types[][10] = { // list of data types
	"double",
	"int",
	"char",
	"float"};
char operators[5] = { // list of operators
	'+',
	'-',
	'/',
	'%',
	'*'};
char brackets[6] = { // list of brackets
	'(',
	')',
	'[',
	']',
	'{',
	'}'};
char special_symbols[12] = { // list of special symbols
	'*',
	';',
	':',
	'.',
	',',
	'^',
	'&',
	'!',
	'>',
	'<',
	'~',
	'`'};

enum TYPE // lexeme type enumerator
{
	IDENTIFIER,
	KEYWORD,
	STRING_LITERAL,
	NUMERIC_CONSTANT,
	OPERATOR,
	BRACKET,
	SPECIAL_SYMBOL,
	RELATIONAL_OPERATOR,
	CHARACTER_CONSTANT
};

char types[][30] = { // map for type to string
	"IDENTIFIER",
	"KEYWORD",
	"STRING_LITERAL",
	"NUMERIC_CONSTANT",
	"OPERATOR",
	"BRACKET",
	"SPECIAL_SYMBOL",
	"RELATIONAL_OPERATOR",
	"CHARACTER_CONSTANT"};

#endif