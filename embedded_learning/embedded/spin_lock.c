#include <stdio.h>
#include <pthread.h> // POSIX threads
#include <unistd.h>  // for sleep function

typedef struct {
    volatile int lock; // Volatile to prevent compiler optimizations
} Spinlock;

void spinlock_init(Spinlock *s) {
    s->lock = 0;
}

void spinlock_lock(Spinlock *s) {
    while (__sync_lock_test_and_set(&s->lock, 1)) {
        // Busy-wait until the lock is acquired
    }
}

void spinlock_unlock(Spinlock *s) {
    __sync_lock_release(&s->lock);
}

// Shared data for the example
int shared_data = 0;
Spinlock spinlock;

// Thread function to increment shared data
void* increment_shared_data(void* arg) {
    for (int i = 0; i < 5; ++i) {
        spinlock_lock(&spinlock);
        int temp = shared_data;
        printf("Thread %d: shared_data = %d\n", *(int*)arg, temp);
        shared_data = temp + 1;
        spinlock_unlock(&spinlock);
        sleep(1);  // Simulate some work
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    int thread_id1 = 1, thread_id2 = 2;

    spinlock_init(&spinlock);

    pthread_create(&thread1, NULL, increment_shared_data, &thread_id1);
    pthread_create(&thread2, NULL, increment_shared_data, &thread_id2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}


#include <stdio.h>
#include <pthread.h> // POSIX threads
#include <unistd.h>  // for sleep function

typedef struct {
    volatile int lock; // Volatile to prevent compiler optimizations
} Spinlock;

void spinlock_init(Spinlock *s) {
    s->lock = 0;
}

void spinlock_lock(Spinlock *s) {
    while (__sync_lock_test_and_set(&s->lock, 1)) {
        // Busy-wait until the lock is acquired
    }
}

void spinlock_unlock(Spinlock *s) {
    __sync_lock_release(&s->lock);
}

// Shared data for the example
int shared_data = 0;
Spinlock spinlock;

// Thread function to increment shared data
void* increment_shared_data(void* arg) {
    for (int i = 0; i < 5; ++i) {
        spinlock_lock(&spinlock);
        int temp = shared_data;
        printf("Thread %d: shared_data = %d\n", *(int*)arg, temp);
        shared_data = temp + 1;
        spinlock_unlock(&spinlock);
        sleep(1);  // Simulate some work
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    int thread_id1 = 1, thread_id2 = 2;

    spinlock_init(&spinlock);

    pthread_create(&thread1, NULL, increment_shared_data, &thread_id1);
    pthread_create(&thread2, NULL, increment_shared_data, &thread_id2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
