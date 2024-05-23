// original format program of stack using linked list 


#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void display();

struct node {
    int data;
    struct node *next;
} *top = NULL;

void main() {
    int choice;
    while (1) {
        printf("\nStack Operations:\n1.Push 2.Pop");
        printf("\n3.Display 4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); display(); break;
            case 2: pop(); display(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n"); break;
        }
    }
}

void push() {
    struct node *var;
    int ele;
    var = (struct node*)malloc(sizeof(struct node));
    printf("Enter a value to be pushed onto the stack: ");
    scanf("%d", &ele);
    var->data = ele;
    var->next = top;
    top = var;
}

void pop() {
    struct node *var = top;
    if (top == NULL) {
        printf("\nStack is Empty\n");
    } else {
        printf("\nPopped element is: %d\n", var->data);
        top = top->next;
        free(var);
    }
}

void display() {
    struct node *var = top;
    if (top == NULL) {
        printf("\nStack is Empty\n");
    } else {
        printf("\nStack elements:\n");
        while (var != NULL) {
            printf("%d\n", var->data);
            var = var->next;
        }
    }
}
