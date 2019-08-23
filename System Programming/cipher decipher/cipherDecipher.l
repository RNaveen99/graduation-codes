/* Cipher decipher */
%{
    void display(int);
%}

%%
[XYZxyz] {
    int bit = -23;
    display(bit);
}
[a-wA-W] {
    int bit = 3;
    display(bit);
}
%%

void display(bit) {
    char ch = yytext[0] + bit;
    // int temp1 = yytext;
    // int temp2 = yytext[0];
    // char temp3 = yytext;
    // char temp4 = yytext[0];
    printf("%c", ch);
    // printf("[%d][%d][%c][%c][%c]", temp1, temp2, temp3, temp4, temp5);.
}

int main() {
    yylex();
    return 0;
}
int yywrap() {
    return 1;
}