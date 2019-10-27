%{
    #include "y.tab.h"
    #undef yywrap
    #define yywrap() 1
%}

%%

a {     return A;}
b {     return B;}
\n {    return NEWLINE;}
[ ] ;
.   {   return OTHER;}

%%
