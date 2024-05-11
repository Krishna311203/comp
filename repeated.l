%{
#include <stdio.h>
#include <string.h>
%}
DIGIT [0-9]
%%
{DIGIT}+ {
int freq[10] = {0};
int i;
int len = strlen(yytext);
for (i = 0; i < len; i++) {
freq[yytext[i] - '0']++;
}
int repeated = 0;
for (i = 0; i < 10; i++) {
if (freq[i] > 1) {
repeated++;
printf("%d ", i);
}
}
if (repeated <= 1) {
printf("\n");
} else {
printf("from %s\n", yytext);
}
}
.|\n ;
%%
int yywrap() {
return 1;

}
int main() {
yylex();
return 0;
}