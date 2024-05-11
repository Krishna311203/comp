%{ 
#include<stdio.h> 
#include<string.h> 
#include<ctype.h> 
int line=0;
int i=0; 
%} 

%% 
"if"|"else"|"char"       {for(i=0;i<yyleng;i++){printf("%c",toupper(yytext[i]));}}
\n                        {return 0;}

%% 
int yywrap(void){} 

int main()
{ 
// The function that starts the analysis 
yylex(); 


	return 0; 
} 
