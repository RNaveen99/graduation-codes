%%
[ \t]+$ {
    printf("space at end [%s]", yytext);
}
[ \t]+ {
    printf("space within [%s]", yytext);
}

. {
    printf("[[%s]]", yytext);
}
%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}