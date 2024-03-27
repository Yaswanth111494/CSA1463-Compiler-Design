#include <stdio.h>
#include <stdlib.h>

#define IN 1
#define OUT 0

int main() {
    char c;
    int charCount = 0, wordCount = 0, lineCount = 0;
    int state = OUT;

    printf("Enter text (press Ctrl+D to end):\n");

    while ((c = getchar()) != EOF) {
        charCount++;

        if (c == '\n') {
            lineCount++;
        }

        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            wordCount++;
        }
    }

    printf("Number of characters: %d\n", charCount);
    printf("Number of words: %d\n", wordCount);
    printf("Number of lines: %d\n", lineCount);

    return 0;
}

