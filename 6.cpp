#include <stdio.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_LEN 100

char nonTerminals[MAX_RULES];
char productions[MAX_RULES][MAX_LEN];
int numProductions[MAX_RULES];

void eliminateLeftRecursion(int numNonTerminals) {
    for (int i = 0; i < numNonTerminals; i++) {
        char A = nonTerminals[i];
        for (int j = 0; j < i; j++) {
            char B = nonTerminals[j];
            for (int k = 0; k < numProductions[i]; k++) {
                if (productions[i][k] == B) {
                    char newProd[MAX_LEN];
                    strcpy(newProd, productions[i]);
                    newProd[k] = '\0';

                    char beta[MAX_LEN];
                    strcpy(beta, &productions[i][k + 1]);

                    for (int l = 0; l < numProductions[j]; l++) {
                        char newProd2[MAX_LEN];
                        sprintf(newProd2, "%c%s%c'", nonTerminals[i], beta, nonTerminals[i]);
                        strcat(newProd2, &productions[j][l]);
                        strcpy(productions[numNonTerminals], newProd2);
                        numProductions[numNonTerminals]++;
                    }

                    sprintf(productions[i], "%s%c'", newProd, nonTerminals[i]);
                    strcpy(productions[numNonTerminals], "#");
                    numProductions[numNonTerminals]++;
                    numNonTerminals++;
                }
            }
        }
    }
}

int main() {
    int numNonTerminals;
    printf("Enter number of non-terminals: ");
    scanf("%d", &numNonTerminals);

    printf("Enter non-terminals separated by space: ");
    for (int i = 0; i < numNonTerminals; i++) {
        scanf(" %c", &nonTerminals[i]);
        numProductions[i] = 0;
    }

    for (int i = 0; i < numNonTerminals; i++) {
        printf("Enter number of productions for %c: ", nonTerminals[i]);
        scanf("%d", &numProductions[i]);

        printf("Enter productions for %c separated by space: ", nonTerminals[i]);
        for (int j = 0; j < numProductions[i]; j++) {
            scanf(" %s", productions[i]);
        }
    }

    eliminateLeftRecursion(numNonTerminals);

    printf("\nGrammar after eliminating left recursion:\n");
    for (int i = 0; i < numNonTerminals; i++) {
        printf("%c -> ", nonTerminals[i]);
        for (int j = 0; j < numProductions[i]; j++) {
            printf("%s ", productions[i][j] == '#' ? "" : productions[i]);
        }
        printf("\n");
    }

    return 0;
}

