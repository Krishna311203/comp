%{
    #include <stdio.h>
    #include <string.h>
%}

KW_WHILE "while"
LPAREN   "("
RPAREN   ")"
LBRACE   "{"
RBRACE   "}"

%%
{KW_WHILE}             { printf("for"); }
{LPAREN}               { printf("("); }
[a-zA-Z][a-zA-Z0-9]*   { printf("%s", yytext); }
{RPAREN}               { printf(") "); }
{LBRACE}               { printf("{ "); }
{RBRACE}               { printf("} "); }
.                      { printf("%s", yytext); }
%%

int yywrap(){}

int main() {
    yylex();
    return 0;
}