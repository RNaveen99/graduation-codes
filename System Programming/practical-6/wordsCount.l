%{
    int words = 0;
    int chars = 0;
    int spaces = 0;
    int lines = 0;
%}
WORDS [a-zA-Z0-9_]+
SPACES [ \t]
NEWLINE \n
%%
{WORDS} {
    words++;
    chars += yyleng;
}
{SPACES} {
    spaces++;
}
{NEWLINE} {
    lines++;
}
. {
    chars++;
}
%%
int main() {
    yyin = fopen("wordsCount.txt", "r");
    yylex();
    printf("No. of words = %d\n", words);
    printf("No. of chars = %d\n", chars);
    printf("No. of spaces = %d\n", spaces);
    printf("No. of \\n encountered = %d\n", lines);
    return 0;
}
int yywrap() {
    return 1;
}