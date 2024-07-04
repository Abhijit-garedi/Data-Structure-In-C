// Design, Develop and Implement a menu driven Program in C for the following operations on
// QUEUE of Characters (Array Implementation of Queue with maximum size MAX)
// a. Insert an Element into QUEUE
// b. Delete an Element from QUEUE
// c. Display the status (No. of elements, Empty/Full/not) of QUEUE
// d. Exit


 #include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    char queue[MAX];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

int isEmpty(Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

void insert(Queue *q, char element) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->queue[++q->rear] = element;
    printf("Inserted %c\n", element);
}