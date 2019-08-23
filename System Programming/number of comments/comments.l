%{
    /* To count the occurence of multi-line comment and single-line comment */
    int multiLine = 0;
    int singleLine = 0;    
%}
KNOSTAR [^*]*
NOSTARFWDSLASH [^*/]
PSTAR \*+
%%
\"(\\.|[^"\\])*\"; {
    printf("%s", yytext);
}
"/*"{KNOSTAR}{PSTAR}({NOSTARFWDSLASH}{KNOSTAR}{PSTAR})*"/" {
    multiLine++;
}
"//".* {
    singleLine++;
}
%%

int main() {
    yyin = fopen("comments.cpp", "r");
    yylex();
    printf("Multi-line comments = %d \n", multiLine);
    printf("Single-line comments = %d\n", singleLine);
    return 0;
}
int yywrap() {
    return 1;
}