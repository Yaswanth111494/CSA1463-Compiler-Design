#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '=' || ch == '<' || ch == '>';
}

bool isValidIdentifierChar(char ch) {
    return isalpha(ch) || ch == '_';
}

bool isDigit(char ch) {
    return isdigit(ch);
}

void printOperators(const char* sourceCode) {
    int len = strlen(sourceCode);
    printf("Operators in the input source code:\n");
    for (int i = 0; i < len; i++) {
        if (isOperator(sourceCode[i])) {
            printf("%c ", sourceCode[i]);
        }
    }
    printf("\n");
}

void printIdentifiers(const char* sourceCode) {
    int len = strlen(sourceCode);
    printf("Identifiers in the input source code:\n");
    for (int i = 0; i < len; i++) {
        if (isValidIdentifierChar(sourceCode[i])) {

            printf("%c", sourceCode[i]);
            while (isValidIdentifierChar(sourceCode[i + 1]) && i + 1 < len) {
                printf("%c", sourceCode[i + 1]);
                i++;
            }
            printf("\n");
        }
    }
}

void printConstants(const char* sourceCode) {
    int len = strlen(sourceCode);
    printf("Constants in the input source code:\n");
    for (int i = 0; i < len; i++) {
        if (isDigit(sourceCode[i])) {
            printf("Constant: ");
            printf("%c", sourceCode[i]);
            while (isDigit(sourceCode[i + 1]) && i + 1 < len) {
                printf("%c", sourceCode[i + 1]);
                i++;
            }
            printf("\n");
        }
    }
}

int main() {
    char sourceCode[1000];
    printf("Enter your C source code:\n");
    fgets(sourceCode, sizeof(sourceCode), stdin); 
    sourceCode[strcspn(sourceCode, "\n")] = '\0';

    printOperators(sourceCode);
    printIdentifiers(sourceCode);
    printConstants(sourceCode);
    return 0;
}
