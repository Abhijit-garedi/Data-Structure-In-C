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
        printf("\nEnter your choice:");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("\nEntered Wrong Choice"); break;
        }
    }
    return 0;
}

void push()
{
    int data;
    printf("\nEnter data:");
    scanf("%d", &data);

    if (top == max - 1)
    {
        printf("\nStack is full");
    }
    else
    {
        stack[++top] = data;
        printf("\n%d pushed into the stack", data);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("\n%d is deleted from the stack", stack[top--]);
    }
}

void display()
{
    if (top == -1)
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("\nElements in the stack are:");
        for (int i = top; i >= 0; i--)
        {
            printf("\n%d", stack[i]);
        }
    }
}
