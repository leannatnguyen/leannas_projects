#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct person{
    char name[MAX_NAME];
    int age;
    struct person *next;
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

// void print_table() {
//     for (int i = 0; i < TABLE_SIZE; i++){
//         if (hash_table[i] == NULL){
//             printf("\t%i\t---\n",i);
//         }
//         else{
//             printf("\t%i\t%s\n", i,hash_table[i]->name);
//         }
//     }
// }

bool hash_table_insert(person *p){
    if (p == NULL){
        return false;
    }
    int i = hash(p->name); //generate the unique input (key)
    p->next = hash_table[i];
    hash_table[i] = p;
    return true;
}

// find a person in the table by their name
person *hash_table_lookup(char *name){
    int index = hash(name); // kinda produces a key
    
}

//delete a person from the hash table
person *hash_table_delete(char *name){
    int index = hash(name); 
    person *temp = hash_table[index]; // get a pointer to a person from the hash table
    person *prev = NULL;
    //while the person exists + it's a different string (name) (basically traverse down linked list until u find the name u want)
    while (temp != NULL && strncmp(temp->name, name, MAX_NAME) != 0){
        prev = temp;    //store the previous node
        temp = temp->next;  //point to the next node of the current node
    }
    //got to end of the list -> not in the list
    if (temp == NULL){
        return NULL;
    }
    // means we know the match node was the front of the list, otherwise it's in the middle or end of the list
    if (prev == NULL){
        //deleting the head
        hash_table[index] = temp->next; //removing the head node and pointing it to the next node
    }
    else{
        //point to the current node's next node (aka remove it)
        prev->next = temp->next;
    }
    return temp;
}

int main(){

    // init_hash_table();
    // print_table();

    
    return 0;
}