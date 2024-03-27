#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

// Structure to represent a symbol table entry
typedef struct {
    char* name;
    int value;
} Entry;

// Structure to represent a symbol table
typedef struct {
    Entry* entries[SIZE];
    int count;
} SymbolTable;

// Initialize the symbol table
void initialize(SymbolTable* symbolTable) {
    symbolTable->count = 0;
    for (int i = 0; i < SIZE; i++) {
        symbolTable->entries[i] = NULL;
    }
}

// Insert an entry into the symbol table
void insert(SymbolTable* symbolTable, const char* name, int value) {
    if (symbolTable->count >= SIZE) {
        printf("Symbol table overflow\n");
        return;
    }

    Entry* entry = (Entry*)malloc(sizeof(Entry));
    entry->name = strdup(name);
    entry->value = value;
    symbolTable->entries[symbolTable->count++] = entry;
}

// Lookup an entry in the symbol table
int lookup(SymbolTable* symbolTable, const char* name) {
    for (int i = 0; i < symbolTable->count; i++) {
        if (strcmp(symbolTable->entries[i]->name, name) == 0) {
            return symbolTable->entries[i]->value;
        }
    }
    return -1; // Not found
}

// Delete an entry from the symbol table
void deleteEntry(SymbolTable* symbolTable, const char* name) {
    for (int i = 0; i < symbolTable->count; i++) {
        if (strcmp(symbolTable->entries[i]->name, name) == 0) {
            free(symbolTable->entries[i]->name);
            free(symbolTable->entries[i]);
            symbolTable->entries[i] = symbolTable->entries[symbolTable->count - 1];
            symbolTable->count--;
            return;
        }
    }
    printf("Entry '%s' not found\n", name);
}

// Test function to demonstrate symbol table operations
void testSymbolTable() {
    SymbolTable symbolTable;
    initialize(&symbolTable);

    insert(&symbolTable, "x", 10);
    insert(&symbolTable, "y", 20);

    printf("Value of x: %d\n", lookup(&symbolTable, "x"));
    printf("Value of y: %d\n", lookup(&symbolTable, "y"));
    printf("Value of z: %d\n", lookup(&symbolTable, "z"));

    deleteEntry(&symbolTable, "y");
    printf("Value of y after deletion: %d\n", lookup(&symbolTable, "y"));
}

int main() {
    testSymbolTable();
    return 0;
}

