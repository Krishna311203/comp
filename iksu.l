%{ 
#include<stdio.h> 
#include<string.h> 
int line=0;
int c=0; 
%} 

%% 
"if"|"else"|"char"|"switch"    {printf("keyword");}
^[0-9]*               {printf("unsigned");}
^[-+]?[0-9]+           {printf("signed");}
^[a-zA-Z][a-zA-Z0-9_]* {printf("identifier");}
.                        {printf("invalid");}                       
%% 
int yywrap(void){} 

int main()
{ 

yylex(); 
return 0; 
} 
