#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "lexicalAnalyzer.h"
#include "initializer.h"

FILE *f1;

struct token tkn;

void program();
void declarations();
int data_type();
void identifier_list(struct token);
void assign_stat(struct token);

void printValid(){
    printf("\n *** Sucessful! ***\n");
    exit(0);
}

void printInvalid(struct token *tkn){
    printf("Error at row: %d, Column: %d for lexeme \" %s \" \n", tkn->row, tkn->col, tkn->lexeme);
    printf("\n *** Unsucessful! ***\n");
    exit(0);
}


void program(){
    tkn = getNextToken(f1);
    if (strcmp(tkn.lexeme, "main") == 0){
        tkn = getNextToken(f1);
        if (strcmp(tkn.lexeme, "(") == 0){
            tkn = getNextToken(f1);
            if (strcmp(tkn.lexeme, ")") == 0){
                tkn = getNextToken(f1);
                if (strcmp(tkn.lexeme, "{") == 0){
                    declarations();
                    tkn = getNextToken(f1);
                    if (strcmp(tkn.lexeme, "}") == 0)
                        return;
                    else
                        printInvalid(&tkn);
                }
                else
                    printInvalid(&tkn);
            }
            else
                printInvalid(&tkn);
        }
        else
            printInvalid(&tkn);
    }
    else
        printInvalid(&tkn);
}

void declarations(){
    tkn = getNextToken(f1);
    if (data_type(tkn.lexeme)){
        tkn = getNextToken(f1);
        identifier_list(tkn);
        tkn = getNextToken(f1);
        if (strcmp(tkn.lexeme, ";") == 0)
            declarations();
        else
            printInvalid(&tkn);
    }
    else
        assign_stat(tkn);
}

int data_type(char *lx){
    if (strcmp(lx, "int") == 0 || strcmp(lx, "char") == 0)
        return 1;
    else
        return 0;
}

void identifier_list(struct token tkn){
    struct token tkn2;
    tkn2 = tkn;
    if (strcmp(tkn2.type, "Identifier") == 0){
        tkn2 = getNextToken(f1);
        if (strcmp(tkn2.lexeme, ",") == 0){
            tkn2 = getNextToken(f1);
            identifier_list(tkn2);
        }
        else if (strcmp(tkn2.lexeme, ";") == 0){
            fseek(f1, -1, SEEK_CUR);
            return;
        }
        else
            printInvalid(&tkn2);
    }
}


void assign_stat(struct token tkn){
    struct token tkn2;
    if (strcmp(tkn.type, "Identifier") == 0){
        tkn2 = getNextToken(f1);
        if (strcmp(tkn2.lexeme, "=") == 0){
            tkn2 = getNextToken(f1);
            if (strcmp(tkn2.type, "Number") == 0 || strcmp(tkn2.type, "Identifier")){
                tkn2 = getNextToken(f1);
                if (strcmp(tkn2.lexeme, ";") == 0)
                    return;
                else
                    printInvalid(&tkn);
            }
            else
                printInvalid(&tkn);
        }
        else
            printInvalid(&tkn);
    }
}


int main(){
    f1 = fopen("sampleParser.c", "r");
    if (f1 == NULL){
        printf("Error! File cannot be opened!\n");
        return 0;
    }
    struct sttable st[10][100];
    int flag = 0, i = 0, j = 0;
    int tabsz[10];
    char w[25];
    w[0] = '\0';
    program();
    printValid();
}