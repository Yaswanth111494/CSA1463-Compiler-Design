#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool checkGrammar(char *input) {
    int len = strlen(input);
    if (len < 2)
        return false;

    if (input[0] == 'a' && input[len - 1] == 'b')
        return true;
    else
        return false;
}

int main() {
    char input[100];

    printf("Enter an input string: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    if (checkGrammar(input))
        printf("Input string satisfies the grammar.\n");
    else
        printf("Input string does not satisfy the grammar.\n");

    return 0;
}

