%{
    #include<stdio.h>
    #include<stdlib.h>
    int yylex();    
    int yyerror(char const *s) {
        printf("Language Not Accepted\n");
        return 1;
    }
%}

%token A B NEWLINE OTHER

%%

start : expr NEWLINE {
    printf("\n Language Accepted \n");
    exit(1);
}
;

expr:   A expr B
    |   A B
    ;
%%

int main() {
    yyparse();
    return 1;
}