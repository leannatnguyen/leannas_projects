#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define EMPTY (-1)
#define STACK_EMPTY INT_MIN

typedef struct node {
    int value;
    struct node *next;
} node;

//how to have many different stacks!
typedef node *stack;
//node* head = NULL; //front of list aka the TOP of the stack

bool push(stack *mystack, int value){
    node *newnode = malloc(sizeof(node));
    
    if (newnode == NULL){
        return false;
    }

    newnode->value = value;
    newnode->next = *mystack; //(remember head was null, after first addition to stack we are gonna push
                            // head to the bottom of the stack)
    *mystack = newnode; // now our new node is the top of the stack
    return true;
}

int pop(stack *mystack){
    if (*mystack == NULL){
        return STACK_EMPTY;
    }

    int result = (*mystack)->value; //save value at the top of the stack
    node* temp = *mystack; //save the head
    *mystack = (*mystack)->next; // update head to the next node
    free(temp); //free the node at the top of the list
    return result;
}

int main(){
    stack s1 = NULL, s2 = NULL, s3 = NULL;

    push(&s1, 56);
    push(&s2, 21);
    push(&s2, 19);
    push(&s2, 70);
    push(&s3, 1);

    int t;
    while((t = pop(&s2)) != STACK_EMPTY){
        printf("t = %d\n", t);
    }
    return 0;
}