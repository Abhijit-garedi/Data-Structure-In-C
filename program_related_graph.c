// simple program related to graph

 #include <stdio.h>
#define MAX 10

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = value;
        printf("Pushed %d into the stack\n", value);
    }
}
