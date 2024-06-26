// program for runnig in college lab system
#include <stdio.h>
#include <stdlib.h>

#define max 5
int stack[max];
int top = -1;

void push();
void pop();
void display();

int main()
{
    int ch;

    while (1)
    {
        printf("\n\nStack Operations:\n1.Push 2.Pop 3.Display 4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("\nEntered Wrong Choice\n"); break;
        }
    }
    return 0;
}

void push()
{
    int data;
    printf("Enter data: ");
    scanf("%d", &data);

    if (top == max - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        stack[++top] = data;
        printf("%d pushed into the stack\n", data);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("%d is deleted from the stack\n", stack[top--]);
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Elements in the stack are:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}
