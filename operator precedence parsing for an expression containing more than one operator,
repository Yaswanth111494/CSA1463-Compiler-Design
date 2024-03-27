#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

double eval_expression(char *expr);

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

double number() {
    double result = 0;
    int sign = 1;

    if (*input == '-') {
        sign = -1;
        advance();
    }

    while (isdigit(*input)) {
        result = result * 10 + (*input - '0');
        advance();
    }

    if (*input == '.') {
        advance();
        double fraction = 0.1;
        while (isdigit(*input)) {
            result += (*input - '0') * fraction;
            fraction *= 0.1;
            advance();
        }
    }

    return result * sign;
}

double exponentiation() {
    double result = number();
    while (*input == '^') {
        advance();
        result = pow(result, exponentiation());
    }
    return result;
}

double term() {
    double result = exponentiation();
    while (*input == '*' || *input == '/') {
        char op = *input;
        advance();
        double factor = exponentiation();
        if (op == '*')
            result *= factor;
        else if (factor != 0)
            result /= factor;
        else {
            printf("Division by zero error\n");
            error = 1;
            return 0;
        }
    }
    return result;
}

double expr() {
    double result = term();
    while (*input == '+' || *input == '-') {
        char op = *input;
        advance();
        double termResult = term();
        if (op == '+')
            result += termResult;
        else
            result -= termResult;
    }
    return result;
}

int main() {
    char buffer[100];

    printf("Enter an arithmetic expression: ");
    fgets(buffer, sizeof(buffer), stdin);

    input = buffer;

    double result = expr();

    if (!error && *input == '\n') {
        printf("Result: %.2f\n", result);
    } else {
        printf("Error in expression\n");
    }

    return 0;
}

