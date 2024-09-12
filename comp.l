%{
#include <stdlib.h>
#include "comp.h"
#include "y.tab.h"
void yyerror(char *);
%}

%%

[a-z]       { 
                yylval.sIndex = *yytext - 'a';
                return VARIABLE;
            }

0           {
                yylval.iValue = atoi(yytext);
                return INTEGER;
            }

[1-9][0-9]* {
                yylval.iValue = atoi(yytext);
                return INTEGER;
            }

[-()<>=+*/;{}.] {
                return *yytext;
             }

">="            return GE;
"<="            return LE;
"=="            return EQ;
"!="            return NE;
"while"         return WHILE;
"do"            return DO;
"for"           return FOR;
"if"            return IF;
"else"          return ELSE;
"print"         return PRINT;

[ \t\n]+        ;       /* ignorar espacios en blanco */

"//".*                { /* ignorar comentarios de una línea */ }
"/*"([^*]|\*[^/])*"*/"  { /* ignorar comentarios de varias líneas */ }






.               yyerror("Unknown character");
%%
int yywrap(void) {
    return 1;
}
