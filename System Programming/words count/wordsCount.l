%{
    int words = 0;
    int chars = 0;
    int spaces = 0;
    int lines = 0;
    int punctuation = 0;
    int numerics = 0;
%}
WORDS [ ]*[a-zA-z]*[ ]*
PUNCTUATION [ ]*[?.!][ ]*
DIGITS [ ]*[0-9]*[ ]*
%%
{WORDS} {
    printf("Word = %s\n", yytext);
    words++;
}
{PUNCTUATION} {
    printf("Punctuation = %s\n", yytext);
    punctuation++;
}
{DIGITS} {
    printf("Numerics = %s\n", yytext);
    numerics++;
}
%%
int main() {
    yyin = fopen("wordsCount.txt", "r");
    yylex();
    printf("No. of words = %d\n", words);
    printf("No. of words = %d\n", words);
    printf("No. of numerics = %d\n", numerics);
    return 0;
}
int yywrap() {
    return 1;
}