#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/* queue
-FIFO
-but we access at both ends!
-head + tail

2 operations:
-enqueue: add something to end of list
-dequeue: remove from front of list

-use queue: when u wanna take care of stuff in terms of arrival
*/

// Linked list imeplementation

#define EMPTY (-1)
#define QUEUE_EMPTY INT_MIN

typedef struct node {
    int value;
    struct node *next;
} node;

//how to have many different queues!
typedef struct {
    node *head;
    node *tail;
} queue;

void init_queue(queue *q){
    q->head = NULL;
    q->tail = NULL;
}

bool enqueue(queue *q, int value){
    node *newnode = malloc(sizeof(node));
    //check if malloc failed
    if (newnode == NULL){
        return false;
    }

    newnode->value = value; //set value
    newnode->next = NULL;   //set the new nodes next to null
    //if there's a tail, conenct the tail to the new node
    if(q->tail != NULL){
        q->tail->next = newnode; //set the queue's tail's next to this new node
    }
    q->tail = newnode; //set the tail to the new node
    
    //make sure head makes sense
    if (q->head == NULL){
        q->head = newnode;
    }
    
    return true;
}

int dequeue(queue *q){
    //check if queue empty
    if (q->head == NULL){
        return QUEUE_EMPTY;
    }

    node *temp = q->head; //get the head of the queue (this is what we want to remove)
    int result = temp->value; //save the head value so you can return

    //want to set the head to the next
    q->head =  q->head->next;
    
    if (q->head == NULL){
        q->tail = NULL;
    }
    free(temp);
    return result;
}

int main(){
    queue q1, q2, q3;
    init_queue(&q1);
    init_queue(&q2);
    init_queue(&q3);
    enqueue(&q1, 56);
    enqueue(&q2, 21);
    enqueue(&q2, 19);
    enqueue(&q2, 70);
    enqueue(&q3, 1);

    int t;
    while((t = dequeue(&q2)) != QUEUE_EMPTY){
        printf("t = %d\n", t);
    }
    return 0;
}