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
  
  void delete(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Deleted %c\n", q->queue[q->front++]);
    if (q->front > q->rear) {
        q->front = q->rear = -1; // Reset queue
    }
}  
   void displayStatus(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%c ", q->queue[i]);
        }
        printf("\n");
        printf("Number of elements: %d\n", q->rear - q->front + 1);
    }
}

int main() {
    Queue q;
    initializeQueue(&q);
    int choice;
    char element;

    do {
        printf("\nQueue Operations Menu:\n");
        printf("1. Insert an Element into QUEUE\n");
        printf("2. Delete an Element from QUEUE\n");
        printf("3. Display the status of QUEUE\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf(" %c", &element);
                insert(&q, element);
                break;
            case 2:
                delete(&q);
                break;
            case 3:
                displayStatus(&q);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
