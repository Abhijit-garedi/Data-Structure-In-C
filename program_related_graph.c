// simple program related to graph 

 #include <stdio.h>
#define MAX 10

int stack[MAX];
int top = -1;


// push section code (line 11 to 19)
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = value;
        printf("Pushed %d into the stack\n", value);
    }
}


// for pop ( 23-33)
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        int value = stack[top];
        top--;
        printf("Popped %d from the stack\n", value);
        return value;
    }
}


// for peek(37-44)
int peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return stack[top];
    }
}


// for displaying( 48-57)
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}


// last section for printing results 
int main() {
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    printf("Top element is %d\n", peek());
    return 0;
}
