%{
#include<stdio.h>
#include<string.h>
int count_a=0;
int count_b=0;
%}

%%
[a]   {count_a++;}
[b]   {count_b++;}
\n     {if(count_a%2==0 &&  count_b%2!=0){ printf("valid %s\n",yytext); } else{printf("invalid %s\n",yytext );} } 
%% 

int yywrap(void){}
 int main(){
yylex();
return 0;
}


