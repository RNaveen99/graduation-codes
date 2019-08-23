/* To identify the max length word */
%{
    #include<stdio.h>
    #include<stdlib.h>
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
        s = (char*)malloc(yyleng);
        strcpy(s, yytext);
    }
}
[\n] {
    printf("max length word = %s \n", s);
    temp = max = 0;
}


%%

int main() {
    yylex();
    return 0;
}
int yywrap() {
    return 1;
}