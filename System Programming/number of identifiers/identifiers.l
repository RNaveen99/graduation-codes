%{
    /* To count the number of identifiers */
    int identifiers = 0;    
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
. ;
%%

int main() {
    yyin = fopen("identifiers.cpp", "r");
    yylex();
    printf("\nint Number of identifiers = %d \n", identifiers);
    return 0;
}
int yywrap() {
    return 1;
}