%{
#include <stdio.h>
%}

%%
"while"   { printf("for"); }
"(i<n)"     { printf("(int i=0;i<n;i++)\n"); }
"{"     { printf("{\n"); }
"}"     { printf("\n}"); }
.|\n    { printf("%s", yytext); }
%%
 int yywrap(void){return 1;}
int main() {
    yylex();
    return 0;
}
