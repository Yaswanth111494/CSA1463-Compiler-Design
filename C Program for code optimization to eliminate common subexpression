#include <stdio.h>
#include <string.h>

#define MAX_EXPR_LENGTH 100

typedef struct {
    char expression[MAX_EXPR_LENGTH];
    int address;
} Subexpression;

int main() {
    Subexpression subexpressions[100];
    int subexprCount = 0;

    printf("Enter expressions (press Ctrl+D to end):\n");

    while (scanf("%s", subexpressions[subexprCount].expression) != EOF) {
        subexpressions[subexprCount].address = subexprCount;
        subexprCount++;
    }

    for (int i = 0; i < subexprCount; i++) {
        for (int j = i + 1; j < subexprCount; j++) {
            if (strcmp(subexpressions[i].expression, subexpressions[j].expression) == 0) {
                printf("Common subexpression found:\n");
                printf("Expression: %s\n", subexpressions[i].expression);
                printf("Address: %d and %d\n", subexpressions[i].address, subexpressions[j].address);
            }
        }
    }

    printf("Optimized code:\n");
    for (int i = 0; i < subexprCount; i++) {
        if (subexpressions[i].address != -1) {
            printf("t%d = %s\n", i, subexpressions[i].expression);
            for (int j = i + 1; j < subexprCount; j++) {
                if (strcmp(subexpressions[i].expression, subexpressions[j].expression) == 0) {
                    subexpressions[j].address = -1;
                    printf("t%d = t%d\n", j, i);
                }
            }
        }
    }

    return 0;
}

