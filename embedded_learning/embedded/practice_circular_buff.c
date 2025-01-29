#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct circular_buffer {
    int *buffer;
    int size;
    int num_items;
    int head;
    int tail;
} circular_buffer;

void cb_init(circular_buffer *cb, int max_size){
    cb->buffer = malloc(sizeof(int) * max_size);
    cb->size = max_size;
    cb->num_items = 0;
    cb->head = 0;
    cb->tail = 0;
}

void cb_enqueue(circular_buffer *cb, int data){
    if (cb->num_items == cb->size){
        return;
    }

    cb->num_items++;
    cb->buffer[cb->head] = data;
    cb->head = (cb->head + 1) % cb->size;
}

int cb_dequeue(circular_buffer *cb){
    if (cb->num_items == 0) {
        return;
    }
    int result = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % cb->size;
    cb->num_items--;
    return result;
}

bool cb_empty(circular_buffer *cb){
    return cb->num_items == 0;
}

bool cb_full (circular_buffer *cb){
    return cb->num_items == cb->size;
}


// Initialize the circular buffer
void initBuffer(CircularBuffer *cb, size_t size) {
    cb->buffer = (int *)malloc(size * sizeof(int));
    if (cb->buffer == NULL) {
        perror("Failed to allocate buffer");
        exit(EXIT_FAILURE);
    }
    cb->max = size;
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

// Free the circular buffer
void freeBuffer(CircularBuffer *cb) {
    free(cb->buffer);
}
/******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct CircularBuffer {
    int *buffer;      // Pointer to the buffer array
    size_t head;      // Index for the head
    size_t tail;      // Index for the tail
    size_t max;       // Maximum size of the buffer
    size_t count;     // Current number of elements
} CircularBuffer;


// Initialize the circular buffer
void initBuffer(CircularBuffer *cb, size_t size) {
    cb->buffer = (int *)malloc(size * sizeof(int));
    if (cb->buffer == NULL) {
        perror("Failed to allocate buffer");
        exit(EXIT_FAILURE);
    }
    cb->max = size;
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

// Free the circular buffer
void freeBuffer(CircularBuffer *cb) {
    free(cb->buffer);
}

// Check if the buffer is full
bool isFull(const CircularBuffer *cb) {
    return cb->count == cb->max;
}

// Check if the buffer is empty
bool isEmpty(const CircularBuffer *cb) {
    return cb->count == 0;
}

// Add an element to the buffer (enqueue)
bool enqueue(CircularBuffer *cb, int item) {
    if (isFull(cb)) {
        printf("Buffer is full, cannot enqueue\n");
        return false;
    }
    cb->buffer[cb->tail] = item;
    cb->tail = (cb->tail + 1) % cb->max;
    cb->count++;
    return true;
}

// Remove an element from the buffer (dequeue)
bool dequeue(CircularBuffer *cb, int *item) {
    if (isEmpty(cb)) {
        printf("Buffer is empty, cannot dequeue\n");
        return false;
    }
    *item = cb->buffer[cb->head];
    cb->head = (cb->head + 1) % cb->max;
    cb->count--;
    return true;
}

// Get the number of entries in the buffer
size_t numEntries(const CircularBuffer *cb) {
    return cb->count;
}
