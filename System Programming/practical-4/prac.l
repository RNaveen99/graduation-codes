%{
    /* To count the number of identifiers */
    int identifiers = 0;  
    int posInt = 0;
    int posFloat = 0;
    int negInt = 0;
    int negFloat = 0;
    int singleLineComment = 0;
    int mutiLineComment = 0;  
%}
KNOSTAR [^*]*
NOSTARFWDSLASH [^*/]
PSTAR \*+
KEYWORDS auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while|do
IDENTIFIERS [a-zA-Z_][a-zA-Z_0-9]*
%%
\"(\\.|[^"\\])*\" {
    printf("String Literal = %s\n", yytext);
}
"/*"{KNOSTAR}{PSTAR}({NOSTARFWDSLASH}{KNOSTAR}{PSTAR})*"/" {
    // multi-line comments
}
"//".* {
    // single line comments
}
#.* {
    // pre-processors
}
{KEYWORDS} {
    printf("Keyword = %s\n", yytext);
} 
{IDENTIFIERS} {
    printf("Identifier = %s\n", yytext);
    identifiers++;
}
-[0-9]*\.[0-9]+ {
    negFloat++;
}

\+?[0-9]*\.[0-9]+ {
    posFloat++;
}
-[0-9]+ {
    negInt++;
}
\+?[0-9]+ {
    posInt++;
}
. ;
%%

int main() {
    yyin = fopen("identifiers.cpp", "r");
    yylex();
    printf("\nNumber of identifiers = %d \n", identifiers);
    printf("Numbers of Positive Integers = %d \n", posInt);
    printf("Numbers of Positive Float = %d \n", posFloat);
    printf("Numbers of Negative Integers = %d \n", negInt);
    printf("Numbers of Negative Float = %d \n", negFloat);
    return 0;
}
int yywrap() {
    return 1;
}