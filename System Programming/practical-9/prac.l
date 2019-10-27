%{
    #include<stdio.h>
    #include<stdlib.h>
    #include "y.tab.h"
    #undef yywrap
    #define yywrap() 1
%}

%%

[0-9]+ {
    yylval = atoi(yytext);
    return DIGIT;
}
[a-z][0-9a-z]* return VARIABLE;
[-+*/] return OPERATOR;
. return *yytext;
%%
