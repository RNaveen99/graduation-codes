%{
    #include<stdio.h>
    #include<stdlib.h>
    int yylex();
    int yyerror(char const *s) {
        printf("Invalid Expression\n");
        return 1;
    }
%}

%token DIGIT OPERATOR VARIABLE
%left '-'
%left OPERATOR
%left '(' ')'
%%

start : expr ';' {
    printf("\nValid Expression\n");
    exit(1);
}
;

expr: digVar
  | expr OPERATOR expr
  | '(' expr ')'
  | expr '-' expr
  | '-' expr
  ;

digVar: DIGIT
  | VARIABLE;

%%

int main() {
    yyparse();
    return 1;
}