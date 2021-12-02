#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void initialize(){
    FILE *fa, *fb;
    char filename[100];
    char c, c2;
    fa = fopen("sampleinput.c", "r");
    fb = fopen("sample.c", "w+");
    while ((c = fgetc(fa)) != EOF){
        if (c == ' '){
            putc(c, fb);
            while (c == ' ')
                c = getc(fa);
        }
        if (c == '/'){
            c2 = getc(fa);
            if (c2 == '/'){
                while (c != '\n')
                    c = getc(fa);
            }
            else if (c2 == '*'){
                do{
                    while (c != '*')
                        c = getc(fa);
                    c = getc(fa);
                }while (c != '/');
            }
            else{
                putc(c, fb);
                putc(c2, fb);
            }
        }
        else
            putc(c, fb);
    }
    fclose(fa);
    fclose(fb);
    fa = fopen("sample.c", "r");
    fb = fopen("temporary.c", "w+");
    while ((c = fgetc(fa)) != EOF){
        if (c == '"'){
            putc(c, fb);
            c = getc(fa);
            while (c != '"'){
                putc(c, fb);
                c = getc(fa);
            }
        }
        else if (c == '#'){
            while (c != '\n')
                c = getc(fa);
            c = getc(fa);
        }
        putc(c, fb);
    }
    fclose(fa);
    fclose(fb);
    fa = fopen("temporary.c", "r");
    fb = fopen("sample.c", "w");
    c = getc(fa);
    while (c != EOF){
        putc(c, fb);
        c = getc(fa);
    }
    fclose(fa);
    fclose(fb);
    remove("temporary.c");
}