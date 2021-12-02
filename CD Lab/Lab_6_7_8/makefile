run: main.o
	gcc -o run main.o

main.o: main.c Parser/rdParser.h Parser/Procedures/procedures.h Parser/utils.h Parser/constants.h Parser/Procedures/Assign.h Parser/Procedures/Data_Type.h Parser/Procedures/Decision.h Parser/Procedures/Declarations.h Parser/Procedures/Expression.h Parser/Procedures/Identifier.h Parser/Procedures/Looping.h Parser/Procedures/Operators.h Parser/Procedures/Program.h Parser/Procedures/Statement.h Lexical/lexeme.h Lexical/hash.h Lexical/tables.h Lexical/structs.h Lexical/utils.h Lexical/constants.h Lexical/removePreprocess.h Lexical/removeExcess.h Lexical/getNextToken.h
	gcc -c main.c
