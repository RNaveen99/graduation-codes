%{

#undef yywrap
#define yywrap() 1

%}

%%

[\n] {
    printf("Hello World\n"); 	
}

	
%%

int main()
{
	yylex(); //calling the rules section
    return 0;
}