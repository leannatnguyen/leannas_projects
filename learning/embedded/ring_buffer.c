/*
Implement a circular buffer for storing integers. Your buffer should support the following operations:

init(buffer_size): Initializes the buffer with a given size.
enqueue(value): Adds a value to the buffer. Returns false if the buffer is full, otherwise returns true.
dequeue(): Removes and returns the oldest value from the buffer. Returns -1 if the buffer is empty.
is_full(): Checks if the buffer is full.
is_empty(): Checks if the buffer is empty.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define BUFFER_SIZE 5
#define QUEUE_EMPTY INT_MIN

typedef struct circular_buffer {
    int *buffer;
    int head, tail, num_entries, size;
} circular_buffer;

void circular_buffer_init(circular_buffer *cb, int max_size) {
    cb->size = max_size;
    cb->buffer = malloc(sizeof(int) * cb->size);
    cb->num_entries = 0;
    cb->head = 0;
    cb->tail = 0;
}

bool cb_empty(circular_buffer *cb) {
    return (cb->num_entries == 0);
}

bool cb_full(circular_buffer *cb) {
    return (cb->num_entries == cb->size);
}

void cb_destroy(circular_buffer *cb){
    free(cb->buffer);
}
void enqueue_buffer(circular_buffer *cb, int val) {
    if (cb_full(cb)) {
        return false;
    }
    cb->buffer[cb->tail] = val;
    cb->num_entries++;
    cb->tail = (cb->tail + 1) % cb->size; // wraps tail back around to 0
}

int dequeue_buffer(circular_buffer *cb) {
    int result;

    if (cb_empty(cb)) {
        return QUEUE_EMPTY;
    }

    result = cb->buffer[cb->head];
    cb->head = (cb->head + 1) % cb->size;
    cb->num_entries--;

    return result;
}