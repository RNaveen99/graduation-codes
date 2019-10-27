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

expr:   A A A A A A A A A s B;
s:  A s
    |   A
    ;
%%

int main() {
    yyparse();
    return 1;
}