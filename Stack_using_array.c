#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

int top = -1;
void push();
void pop();
void display();

void main()
{
    int ch;
    clrscr;
    while(1)
    {
        printf("\n\n stack operation : \n 1.push 2.pop 3.display 4.exit \n");
        printf("enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            push();
            display();
            break();

            case 2:
            pop();
            display();
            break();

            case 3: display();
            break;

            case 4: exit();

            default: printf("\nEnter wrong choice:");
            break;

        }
    }
    getch();
}

void push()
{
    int data;
    printf("\nenter data");
    scanf("%d")
}