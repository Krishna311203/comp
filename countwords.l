%{ 
#include<stdio.h> 
#include<string.h> 
int line=0;
int c=0; 
%} 

%% 
[a-zA-Z0-9]*   {c++;}
\n  {printf("%d",c);}
%% 
int yywrap(void){} 

int main()
{ 
// The function that starts the analysis 
yylex(); 


	return 0; 
} 
