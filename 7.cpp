#include <stdio.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_LEN 100

char nonTerminals[MAX_RULES];
char productions[MAX_RULES][MAX_LEN][MAX_LEN]; // Three-dimensional array to store productions
int numProductions[MAX_RULES];

void eliminateLeftFactoring(int numNonTerminals) {
    for (int i = 0; i < numNonTerminals; i++) {
        char A = nonTerminals[i];
        char commonPrefix[MAX_LEN];
        int commonPrefixLen = 0;
        int maxCommonPrefixLen = 0;

        for (int j = 0; j < numProductions[i]; j++) {
            for (int k = j + 1; k < numProductions[i]; k++) {
                commonPrefixLen = 0;
                while (productions[i][j][commonPrefixLen] != '\0' &&
                       productions[i][k][commonPrefixLen] != '\0' &&
                       productions[i][j][commonPrefixLen] == productions[i][k][commonPrefixLen]) {
                    commonPrefix[commonPrefixLen] = productions[i][j][commonPrefixLen];
                    commonPrefixLen++;
                }
                if (commonPrefixLen > maxCommonPrefixLen) {
                    maxCommonPrefixLen = commonPrefixLen;
                    commonPrefix[commonPrefixLen] = '\0';
                }
            }
        }

        if (maxCommonPrefixLen > 0) {
            printf("Left factoring detected for %c with common prefix: %s\n", A, commonPrefix);

            char newNonTerminal = 'A' + i;
            nonTerminals[numNonTerminals] = newNonTerminal;
            numProductions[numNonTerminals] = 0;

            for (int j = 0; j < numProductions[i]; j++) {
                if (strncmp(productions[i][j], commonPrefix, maxCommonPrefixLen) == 0) {
                    strcpy(productions[numNonTerminals][numProductions[numNonTerminals]], &productions[i][j][maxCommonPrefixLen]);
                    numProductions[numNonTerminals]++;
                }
            }

            for (int j = 0; j < numProductions[i]; j++) {
                if (strncmp(productions[i][j], commonPrefix, maxCommonPrefixLen) != 0) {
                    strcpy(productions[i][j], productions[i][j]);
                }
            }

            strcpy(productions[i][numProductions[i]], commonPrefix);
            numProductions[i]++;
            strcpy(productions[i][numProductions[i]], &newNonTerminal);
            numProductions[i]++;

            numNonTerminals++;
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
            scanf(" %s", productions[i][j]);
        }
    }

    eliminateLeftFactoring(numNonTerminals);

    printf("\nGrammar after eliminating left factoring:\n");
    for (int i = 0; i < numNonTerminals; i++) {
        printf("%c -> ", nonTerminals[i]);
        for (int j = 0; j < numProductions[i]; j++) {
            printf("%s ", productions[i][j]);
        }
        printf("\n");
    }

    return 0;
}

