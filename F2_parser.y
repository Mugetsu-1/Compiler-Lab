%{
#include <stdio.h>
#include <stdlib.h>
void yyerror(const char *s);
int yylex();
%}

%token NUMBER ID TYPE
%left '+' '-'
%left '*' '/'

%%
program: program stmt
       |
       ;

stmt: declaration ';' { printf("Valid Declaration\n"); }
    | expr ';'        { printf("Result = %d\n", $1); }
    ;

declaration: TYPE ID
           | TYPE ID '=' expr
           ;

expr: expr '+' expr { $$ = $1 + $3; }
    | expr '-' expr { $$ = $1 - $3; }
    | expr '*' expr { $$ = $1 * $3; }
    | expr '/' expr { $$ = $1 / $3; }
    | '(' expr ')'  { $$ = $2; }
    | NUMBER        { $$ = $1; }
    ;

%%

void yyerror(const char *s) { printf("Error: %s\n", s); }

int main() {
    printf("Enter declarations or expressions ending with semicolon:\n");
    yyparse();
    printf("\nLab No.: 15 | Name: Saugat Bikram Thapa | Roll No./Sec: 80117731/A\n");
    return 0;
}
