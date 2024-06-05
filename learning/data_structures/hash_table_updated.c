#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100000 //represents the max number of items u can store before u get collision
// collision -> 2 keys are diff but hash to same slot in table
// at a given slot there's 2 values: checks first key if not the one it needs then takes the new one

//one entry
typedef struct entry_t{
    char *key;
    char *value;
    struct entry_t *next; //this is for collisions (single linked list)
} entry_t;

//hash table struct --> array of pointers to an entry
typedef struct {
    entry_t **entries;
} ht_t;

unsigned int hash(const char *key){
    unsigned long int value = 0;
    unsigned int key_len = strlen(key);

    for (int i = 0; i < key_len; i++){
        value = value * 37 + key[i];
    }

    value = value % TABLE_SIZE; //value is 0 <= value < table_size
    
    return value;
}

ht_t *ht_create(void){
    //allocate table
    ht_t *hashtable = malloc(sizeof(ht_t)*1);

    //allocate table entries
    hashtable->entries = malloc(sizeof(entry_t*)*TABLE_SIZE);

    //set each entry = null
    for (int i = 0; i < TABLE_SIZE; i++){
        hashtable->entries[i] = NULL;
    }

    return hashtable;
}

int main(int argc, char **argv){
    ht_t *ht = ht_create();

    return 0;
}