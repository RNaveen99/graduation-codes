%{
    /* To count the occurence of +ve Integers, +ve float, -ve Integers, -ve float*/
    int posInt = 0;
    int posFloat = 0;
    int negInt = 0;
    int negFloat = 0;
%}

%%
-[0-9]*\.[0-9]+ {
    negFloat++;
}

\+?[0-9]*\.[0-9]+ {
    posFloat++;
}
-[0-9]+ {
    negInt++;
}
\+?[0-9]+ {
    posInt++;
}
. ;
%%

int main() {
    yyin = fopen("numbers.txt", "r");
    yylex();
    printf("Numbers of Positive Integers = %d \n", posInt);
    printf("Numbers of Positive Float = %d \n", posFloat);
    printf("Numbers of Negative Integers = %d \n", negInt);
    printf("Numbers of Negative Float = %d \n", negFloat);
    return 0;
}
int yywrap() {
    return 1;
}