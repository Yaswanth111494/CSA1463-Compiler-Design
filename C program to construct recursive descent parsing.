#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int expr();
int term();
int factor();

char *input;
int error = 0;

void advance() {
    input++;
    while (*input == ' ') input++;
}

void match(char token) {
    if (*input == token)
        advance();
    else {
        printf("Syntax Error\n");
        error = 1;
    }
}

int number() {
    int result = 0;
    while (isdigit(*input)) {
        result = result * 10 + (*input - '0');
        advance();
    }
    return result;
}

int expr() {
    int result = term();
    while (*input == '+' || *input == '-') {
        char op = *input;
        advance();
        int termResult = term();
        if (op == '+')
            result += termResult;
        else
            result -= termResult;
    }
    return result;
}

int term() {
    int result = factor();
    while (*input == '*' || *input == '/') {
        char op = *input;
        advance();
        int factorResult = factor();
        if (op == '*')
            result *= factorResult;
        else if (factorResult != 0)
            result /= factorResult;
        else {
            printf("Division by zero error\n");
            error = 1;
            return 0;
        }
    }
    return result;
}

int factor() {
    int result;
    if (*input == '(') {
        advance();
        result = expr();
        match(')');
    } else if (isdigit(*input)) {
        result = number();
    } else {
        printf("Syntax Error\n");
        error = 1;
        return 0;
    }
    return result;
}

int main() {
    char buffer[100];

    printf("Enter an arithmetic expression: ");
    fgets(buffer, sizeof(buffer), stdin);

    input = buffer;

    int result = expr();

    if (!error && *input == '\n') {
        printf("Result: %d\n", result);
    } else {
        printf("Error in expression\n");
    }

    return 0;
}

