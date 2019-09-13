%%
[a-zA-Z]+ {
    int i, j;
    for(i = yyleng; i >= 0; i--) {
        for (j = 0; j < i; j++) {
            printf("%c", yytext[j]);
        }
        printf("\n");
    }
}
\n ;
. ;
%%
int main() {
    yylex();
    return 0;
}
int yywrap() {
    return 1;
}