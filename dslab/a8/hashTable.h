#include<string.h>
#define ARRAY_SIZE 7
typedef struct hashTable{
    int table[ARRAY_SIZE];
    int deleted[ARRAY_SIZE];
}hashTable;

hashTable createTable(){
    hashTable t;
    memset(t.table, -1, sizeof(t.table));
    memset(t.deleted, 0, sizeof(t.table));
    return t;
}

void insert(hashTable *t,int key) {
    if (t->table[key % ARRAY_SIZE] == -1) {
        t->table[key % ARRAY_SIZE] = key;
    }
    else {
        int x=0;
        int index = (key + (x*x)) % ARRAY_SIZE;
        while(t->table[index % ARRAY_SIZE] != -1) {
            index = (index + (x*x)) % ARRAY_SIZE;
            x++;
        }
        t->table[(index) % ARRAY_SIZE] = key;
    }
}

int delete(hashTable *t, int key) {
    int index = key % ARRAY_SIZE;
    int x=0;
    while(t->table[index] != -1 || t->deleted[index]) {
        if (t->table[index] == key) {
            t->table[index] = -1;
            t->deleted[index] = 1;
            return 1;
        }
        index = (index + x*x) % ARRAY_SIZE;
        x++;
    }
    return 0;
}

int search(hashTable *t, int key) {
    int index = key % ARRAY_SIZE;
    while(!(t->table[index] == -1 && !t->deleted[index])) {
        if (t->table[index] == key) {
            return 1;
        }
        index = (index + 1) % ARRAY_SIZE;
    }
    return 0;
}
