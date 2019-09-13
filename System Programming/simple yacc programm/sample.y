%{
    #include<stdio.h>
    #include<stdlib.h>
%}

%token DIGIT NEWLINE
%left '+' '-'

%%

start : expr NEWLINE {
    printf("\nComplete\n");
    exit(1);
}
;

expr: expr '+' expr { printf("+ "); }
    | expr '-' expr { printf("- "); }
    | '(' expr ')'
    | DIGIT { printf("%d ", $1); }
    ;

%%

int yyerror(char const *s) {
    printf("yyerror %s\n", s);
    return 1;
}

int main() {
    yyparse();
    return 1;
}