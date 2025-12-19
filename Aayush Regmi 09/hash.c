#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int hashTable[MAX];
int m;

/* Initialize hash table */
void initHashTable() {
    for (int i = 0; i < m; i++) {
        hashTable[i] = -1;   // -1 indicates empty location
    }
}

/* Hash function */
int hashFunction(int key) {
    return key % m;
}

/* Insert key using Linear Probing */
void insert(int key) {
    int index = hashFunction(key);

    // Linear probing on collision
    while (hashTable[index] != -1) {
        index = (index + 1) % m;
    }

    hashTable[index] = key;
}

/* Display hash table */
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < m; i++) {
        if (hashTable[i] == -1)
            printf("HT[%d] --> Empty\n", i);
        else
            printf("HT[%d] --> %d\n", i, hashTable[i]);
    }
}

int main() {
    int n, key;

    printf("Enter size of hash table (m): ");
    scanf("%d", &m);

    initHashTable();

    printf("Enter number of employee records (N): ");
    scanf("%d", &n);

    printf("Enter %d employee keys (4-digit):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }

    display();

    return 0;
}
