#include <stdio.h>
#include <stdint.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

Node* createNewNode(int val) {
    Node* newNode = (Node *)malloc(sizeof(Node));
    if (newNode){
        newNode->val = val;
        newNode->next = NULL;
    }
    return newNode;
}

Node* reverseLinkedList(Node *head){
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr->next;
    }
    head = prev;
    return head;
}

// Implement a queue using arrays?
#define MAX 100
typedef struct Queue {
    int items[MAX];
    int front;
    int back;
    int num_items;
}

Queue* initQueue(){
    Queue *newQueue = (Queue*)malloc(sizeOf(Queue));
    newQueue->front = -1;
    newQueue->back = -1;
    newQueue->num_items = 0;
    return newQueue;
}

bool isFull(Queue *queue){
    return queue->num_items == MAX ? false : true;
}

bool isEmpty(Queue *queue){
    return queue->num_items == 0 ? true : false;
}
void enqueue(Queue *queue, int val){
    if (isFull(queue)) {
        return;
    }
    if (queue->front == -1){
        queue->front = 0;
    }
    queue->rear++;
    queue->items[queue->rear] = val;
    queue->num_items++;
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) return -1;

    int item = queue->items[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = q->rear = -1;
    }
    queue->num_items--;
    return item;
}

// Write a C program to detect a cycle in a linked list
// tortoise and hare algo

int detectCycle(Node *head){
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next; //move slow pointer by one step
        fast = fast->next->next; //move fast pointer by 2 steps
        if (slow == fast) {
            return 1;
        }
    }
    return 0; //no cycle detected
}


// find first non-repeating character in a string in C
#define CHAR_RANGE 256
char firstNonRepeatingChar (char *str) {
    int count[CHAR_RANGE] = {0}; //array to store char count
    for (int i = 0; str[i]; i++){
        count[(unsigned char)str[i]]++;
    }
    for (int i = 0; str[i]; i++){
        if (count[(unsigned char)str[i]] == 1) {
            return str[i];
        }
    }
    return '\0'; //no non-repeating char is found
}

// merge 2 sorted arrays
void mergeArrays(int arr1[], int arr2[], int n1, int n2, int merged[]) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] < arr[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }
    // copy remaining elements of arr1 if any
    while (i < n1){
        merged[k++] = arr1[i++];
    }
    while (j < n2) {
        merged[k++] = arr2[j++];
    }
}