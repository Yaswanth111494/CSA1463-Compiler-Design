#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPR_LENGTH 100

void generate_intermediate_code(char *expr);

int main() {
    char expr[MAX_EXPR_LENGTH];

    printf("Enter an arithmetic expression: ");
    fgets(expr, sizeof(expr), stdin);

    expr[strcspn(expr, "\n")] = '\0';

    generate_intermediate_code(expr);

    return 0;
}

void generate_intermediate_code(char *expr) {
    char intermediate_code[MAX_EXPR_LENGTH * 2];
    int temp_count = 0;

    for (int i = 0; expr[i] != '\0'; i++) {
        if (isdigit(expr[i])) {
            intermediate_code[temp_count++] = expr[i];
        } else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            intermediate_code[temp_count++] = ' ';
            intermediate_code[temp_count++] = expr[i];
            intermediate_code[temp_count++] = ' ';
        } else {
            printf("Invalid character in expression: %c\n", expr[i]);
            exit(1);
        }
    }

    intermediate_code[temp_count] = '\0';

    printf("%s\n", intermediate_code);
}

