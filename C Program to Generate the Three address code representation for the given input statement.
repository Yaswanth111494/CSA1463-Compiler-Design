#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char expr[100];
int temp_count = 0;

void factor();
void term();
void expression();
void emit(char op, char arg1, char arg2, char result);

int main() {
    printf("Enter an arithmetic expression: ");
    fgets(expr, sizeof(expr), stdin);

    expression();

    return 0;
}

void factor() {
    if (isdigit(expr[temp_count])) {
        printf("t%d = %c\n", temp_count, expr[temp_count]);
        temp_count++;
    } else {
        printf("Error: Invalid expression\n");
        exit(1);
    }
}

void term() {
    factor();
    while (expr[temp_count] == '*' || expr[temp_count] == '/') {
        char op = expr[temp_count++];
        factor();
        printf("t%d = t%d %c t%d\n", temp_count, temp_count - 2, op, temp_count - 1);
    }
}

void expression() {
    term();
    while (expr[temp_count] == '+' || expr[temp_count] == '-') {
        char op = expr[temp_count++];
        term();
        printf("t%d = t%d %c t%d\n", temp_count, temp_count - 2, op, temp_count - 1);
    }
}

