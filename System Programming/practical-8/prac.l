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
[-+*/] return OPERATOR;
\t ;
. return *yytext;
%%
