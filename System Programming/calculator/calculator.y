%{
    #include<stdio.h>
    #include<stdlib.h>
%}

%token DIGIT NEWLINE
%left '+' '-' '*' '/' '%'

%%

start : expr NEWLINE {
    printf("\nResult = %d\n", $1);
    exit(1);
}
;

expr: expr '+' expr { $$ = $1 + $3; }
    | expr '-' expr { $$ = $1 - $3; }
    | expr '*' expr { $$ = $1 * $3; }
    | expr '/' expr { $$ = $1 / $3; }
    | expr '%' expr { $$ = $1 % $3; }
    | '(' expr ')' { $$ = $2; }
    | DIGIT { $$ = $1; }
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