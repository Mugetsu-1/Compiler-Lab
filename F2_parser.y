%{
#include <stdio.h>
#include <stdlib.h>
void yyerror(const char *s);
int yylex();
%}

%token NUMBER ID INT
%left '+' '-'
%left '*' '/'

%%
stmt: expr { printf("Result = %d\n", $1); }
    | INT ID { printf("Valid Declaration\n"); }
    ;

expr: expr '+' expr { $$ = $1 + $3; }
    | expr '-' expr { $$ = $1 - $3; }
    | expr '*' expr { $$ = $1 * $3; }
    | expr '/' expr { $$ = $1 / $3; }
    | NUMBER        { $$ = $1; }
    ;

%%

void yyerror(const char *s) { printf("Error: %s\n", s); }

int main() {
    printf("Enter expression or declaration: ");
    yyparse();
    printf("\nLab No.: 15 | Name: Student | Roll No./Sec: 01/A\n");
    return 0;
}