%{
    #include<stdio.h>
    #include<stdlib.h>
    int yylex();
    int yyerror(char const *s) {
        printf("Invalid Expression\n");
        return 1;
    }
%}

%token DIGIT OPERATOR
%left '-'
%left OPERATOR
%left '(' ')'
%%

start : expr ';' {
    printf("\nValid Expression\n");
    exit(1);
}
;

expr: DIGIT
  | expr OPERATOR expr
  | '(' expr ')'
  | expr '-' expr
  | '-' expr
  ;
  
%%

int main() {
    yyparse();
    return 1;
}