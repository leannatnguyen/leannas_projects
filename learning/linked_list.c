#include <stdio.h>
#include <stdlib.h>
/* Linked lists are good to add stuff in the
middle of an "array"

each "box" == node
each connection to a node is "edge"/next pointer

need to keep track of parts of the list:
-starting node == head
-next pointer
-tails if you want to keep track at the end

nodes can be ANYWHERE! can link wherever
*/

struct node {
    int value;
    struct node* next; //next pointer 
};

typedef struct node node_t; // so we don't have to keep typing struct

void printlist(node_t *head){
    node_t *temp = head; //temporary pointer to point at the head
    while(temp){
        printf("%d\n", temp->value);
        temp = temp->next;
    }
}

// make function to add a node at the head of the list
node_t *insert_at_head(node_t *head, node_t *new_node){
    new_node->next = head;
    return new_node;
}

// **head is a pointer to a pointer
node_t *insert_at_head(node_t **head, node_t *new_node){
    new_node->next = *head;
    *head = new_node;
    return new_node;
}

//have a function that returns a pointer to a new node
node_t *create_new_node(int value){
    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = NULL;
    
    return new_node;
}

//function to insert node after any node
void insert_at_tail(node_t *insert_after_node, node_t *new_node){
    //want to capture the "OLD" next node for the new node
    new_node->next = insert_after_node->next; 
    // now u can set the old node to point at the new one
    insert_after_node->next = new_node;
}

//function to find node
node_t *find_node(node_t *head, int value){
    node_t *temp = head;
    while(temp->next != NULL){
        if (temp->value == value){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
int main(){
    node_t *head = NULL;
    node_t *temp;

    // temp = create_new_node(32); // make a new node with value 32, next = NULL
    // head = temp;    //set the head node to the one above
    // temp = create_new_node(45); //make a new node with value 45
    // temp->next = head; //adding to the front of the list

    for (int i = 0; i < 25; i++){
        temp = create_new_node(i); //creates new node with value i
        // first head is NULL so u are making a null pointer = next of new node
        temp->next = head; 
        //now set the head node to temp (your new node)
        head = temp;
    }

    /*** EXAMPLE ***
    node_t *n1, n2, n3;
    node_t *head; // head node pointer
    //HOW TO USUALLY DO
    n1 = malloc(sizeof(node_t));
    //


    n1.value = 45;
    n2.value = 8;
    n3.value = 32;
    // say n3 -> n2 -> n1
    head = &n3;
    n3.next = &n2;
    n2.next = &n1;
    n1.next = NULL; //nothing after this guy

    //remove head node
    head = head->next;
    */

    printlist(head);

    return 0;
}