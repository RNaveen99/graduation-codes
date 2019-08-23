%{

%}
%%
[\t ]+ {
    fprintf(yyout, " ");
}
.|\n {
    fprintf(yyout, "%s", yytext);
}
%%
int main() {
    yyin = fopen("spaces.txt", "r");
    yyout = fopen("spacesNot.txt", "w");
    yylex();
    return 0;
}
int yywrap() {
    return 1;
}