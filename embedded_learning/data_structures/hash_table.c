#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

/* Notes:
-with linked list you have to go sequentially
-hash table should be able to find the item you're looking for in constant time -> O(1)

hash table:
    -array with hash function
    -input -> hash -> index to array
    -same input should ALWAYS have same output
    -results should be pretty random
    -need a fast + unique hash function
    -ideal hash function -> 1:1 input:output

how to deal with collisions:
-open addressing
    -keep everything in table
    -if first location given is full, look for another
        -use hash function again to find a new location
        - or u can just see where the next open spot is
-external chaining
    -simply chain them up -> each becomes a linked list
    */
#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (person*)(0xFFFFFFFFFFFFFFFFUL)

typedef struct {
    char name[MAX_NAME];
    int age;
} person;

person *hash_table[TABLE_SIZE];

void init_hash_table(){
    for (int i = 0; i < TABLE_SIZE; i++){
        hash_table[i] = NULL;
    }
    // table is empty
}


unsigned int hash(char *name){
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++){
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;

}

void print_table() {
    for (int i = 0; i < TABLE_SIZE; i++){
        if (hash_table[i] == NULL){
            printf("\t%i\t---\n",i);
        }
        else{
            printf("\t%i\t%s\n", i,hash_table[i]->name);
        }
    }
}

bool hash_table_insert(person *p){
    if (p == NULL){
        return false;
    }
    int i = hash(p->name); //generate the unique input (key)

    for (int i = 0; i < TABLE_SIZE; i++){
        int try = (i + index) % TABLE_SIZE;
        if (hash_table[try] == NULL || hash_table[try] == DELETED_NODE){
            hash_table[try] = p;
            return true;
        }
    }

    return false;
}

// find a person in the table by their name
person *hash_table_lookup(char *name){
    int index = hash(name); 

    for (int i = 0; i < TABLE_SIZE; i++){
        int try = (index + i)  % TABLE_SIZE;

        if (hash_table[try] == NULL){
            return NULL;
        }
        if (hash_table[try] == DELETED_NODE){
            continue;
        }
         if (strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0){
            return hash_table[try];
            }
    }
}

//delete a person from the hash table
person *hash_table_delete(char *name){
    int index = hash(name); 
    for (int i = 0; i < TABLE_SIZE; i++){
        int try = (index + i)  % TABLE_SIZE;

        if (hash_table[try] == NULL){
            return NULL;
        }
        if (hash_table[try] == DELETED_NODE){
            continue;
        }
        if (hash_table[try] != NULL &&
            strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0){

                person *temp = hash_table[try];
                hash_table[try] = DELETED_NODE;
                return temp;
    
            }
    }
    return NULL;
}

int main(){

    init_hash_table();
    print_table();

    
    return 0;
}