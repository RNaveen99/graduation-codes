/* To identify the max length word */
%{
    #include<string.h>
    int max = 0;
    int temp = 0;
    char *s;
%}

%%
[a-zA-z]+ {
    temp = yyleng;
    if (temp > max) {
        max = temp;
        s = (char*)realloc(s, yyleng);
        strcpy(s, yytext);
    }
}
\n {
    printf("max length word = %s \n", s);
    temp = max = 0;
    s = 0;
}
[ ] ;

%%

int main() {
    yylex();
    return 0;
}
int yywrap() {
    return 1;
}