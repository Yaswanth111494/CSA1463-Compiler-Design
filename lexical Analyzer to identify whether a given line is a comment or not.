#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a character is a comment start
bool isCommentStart(char ch) {
    return ch == '/' ;
}

// Function to check if a character is a comment end
bool isCommentEnd(char ch) {
    return ch == '*';
}

// Function to perform lexical analysis and print comments
void printComments(const char* sourceCode) {
    int len = strlen(sourceCode);
    bool inSingleLineComment = false;
    bool inMultiLineComment = false;

    for (int i = 0; i < len; i++) {
        if (!inSingleLineComment && !inMultiLineComment) {
            if (sourceCode[i] == '/' && sourceCode[i + 1] == '/') {
                inSingleLineComment = true;
                printf("Single Line Comment: ");
                i++; // Skip the second '/' character
            } else if (sourceCode[i] == '/' && sourceCode[i + 1] == '*') {
                inMultiLineComment = true;
                printf("Multi Line Comment: ");
                i++; // Skip the '*' character
            }
        }

        if (inSingleLineComment) {
            if (sourceCode[i] == '\n') {
                inSingleLineComment = false;
                printf("\n");
            } else {
                printf("%c", sourceCode[i]);
            }
        }

        if (inMultiLineComment) {
            printf("%c", sourceCode[i]);
            if (sourceCode[i] == '*' && sourceCode[i + 1] == '/') {
                inMultiLineComment = false;
                printf("*/\n");
                i++; // Skip the '/' character
            }
        }
    }
}

int main() {
    char sourceCode[1000]; // Assuming a maximum input size of 1000 characters
    printf("Enter your C source code:\n");
    fgets(sourceCode, sizeof(sourceCode), stdin); // Read input from standard input

    // Remove newline character from the input
    sourceCode[strcspn(sourceCode, "\n")] = '\0';

    printComments(sourceCode);
    return 0;
}
