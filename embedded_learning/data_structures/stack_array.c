#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/* stack:
-LIFO

2 operations:
-push: put on top
-pop: take off top

following is implementazaTaion using array
*/
#define STACK_LENGTH 5
#define EMPTY (-1)
#define STACK_EMPTY INT_MIN

typedef struct {
    int values[STACK_LENGTH];
    int top;
} stack;


bool push(stack *mystack, int value){
    if (mystack->top >= STACK_LENGTH - 1){   //basically the stack is full (we are at the end)
        return false;
    }
    mystack->top++;
    mystack->values[mystack->top] = value;
    return true;
}

int pop(stack *mystack){
    if (mystack->top == EMPTY){
        return STACK_EMPTY;
    }

    int result = mystack->values[mystack->top];
    mystack->top--; //just moving the top down + will right over it
    return result;
}

int main(){
    stack s1, s2, s3;
    s1.top = EMPTY;
    s2.top = EMPTY;
    s3.top = EMPTY;
    push(&s1,56);
    push(&s2,21);
    push(&s2,22);
    push(&s2,23);
    push(&s3,1);

    int t;
    while((t = pop(&s2)) != STACK_EMPTY){
        printf("t = %d\n", t);
    }
    return 0;
}