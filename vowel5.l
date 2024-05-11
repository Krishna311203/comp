%{ 
#include<stdio.h> 
#include<string.h> 
#include<ctype.h> 
%} 

%% 
[a-z]*[aeiou][a-z]*[aeiou][a-z]*[aeiou][a-z]*[aeiou][a-z]*[aeiou][a-z]*             {printf("Valid %s\n",yytext);}
[a-z]*                                                                                    {printf("inValid %s\n",yytext);}


%% 
int yywrap(void){} 

int main()
{ 
// The function that starts the analysis 
yylex(); 


	return 0; 
} 
