#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct Stack {
    int items[MAX];
    int top;
} Stack;

// Initialize the stack
void initStack(Stack* s) {
    s->top = -1;
}

// Check if the stack is full
bool isFull(Stack* s) {
    return s->top == MAX - 1;
}

// Check if the stack is empty
bool isEmpty(Stack* s) {
    return s->top == -1;
}

// Push an element onto the stack
bool push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return false;
    }
    s->items[++(s->top)] = value;
    return true;
}

// Pop an element from the stack
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1; // Return a sentinel value
    }
    return s->items[(s->top)--];
}

// Peek the top element
int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1; // Return a sentinel value
    }
    return s->items[s->top];
}


/*QUEUE*/
#define MAX 100

typedef struct Queue {
    int items[MAX];
    int front, rear;
} Queue;

// Initialize the queue
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
bool isFull(Queue* q) {
    return q->rear == MAX - 1;
}

// Check if the queue is empty
bool isEmpty(Queue* q) {
    return q->front == -1 || q->front > q->rear;
}

// Enqueue an element
bool enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return false;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->items[++(q->rear)] = value;
    return true;
}

// Dequeue an element
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1; // Return a sentinel value
    }
    int value = q->items[q->front++];
    // Reset front and rear when the queue is empty after dequeue
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return value;
}

// Peek the front element
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1; // Return a sentinel value
    }
    return q->items[q->front];
}
