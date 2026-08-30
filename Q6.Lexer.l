%{
#include <stdio.h>
int line_no = 1;
%}

%%
\n          { line_no++; }
[ \t]+      ;
"//".*      ;
"/*"([^*]|\*+[^/*])*"*"+"/" ;

"int"|"float"|"char"|"if"|"else"|"return" { printf("<KEYWORD, %d %s,>\n", yytext, line_no); }
[a-zA-Z_][a-zA-Z0-9_]*                    { printf("<IDENTIFIER, %d %s,>\n", yytext, line_no); }
[0-9]+\.[0-9]+                            { printf("<FLOAT_CONST, %d %s,>\n", yytext, line_no); }
[0-9]+                                    { printf("<INT_CONST, %d %s,>\n", yytext, line_no); }
"+"|"-"|"*"|"/"|"="                       { printf("<OPERATOR, %d %s,>\n", yytext, line_no); }
";"|","|"("|"}"|"{"|")"                   { printf("<DELIMITER, %d %s,>\n", yytext, line_no); }
.                                         { printf("<UNKNOWN, %d %s,>\n", yytext, line_no); }
%%

int main() {
    yylex();
    printf("\nLab No_Q.: 6 | Name: Saugat Bikram Thapa | Roll No./Sec: 80117731/A\n");
    return 0;
}

int yywrap() {
    return 1;
}
