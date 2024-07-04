//Develop and Implement a Program in C for converting an Infix Expression to Postfix
// Expression. Program should support for both parenthesized and free parenthesized expressions
// with the operators: +, -, *, /, %(Remainder), ^(Power) and alphanumeric operands.


 // not completely sure about that 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack type
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

// Stack Operations
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

 char peek(struct Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top];
}

// Function to check if the given character is operand
int isOperand(char ch) {
    return (isdigit(ch) || isalpha(ch));
}

// Function to return precedence of operators
int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}
   

   void infixToPostfix(char* exp) {
    int i, k;

    struct Stack* stack = createStack(strlen(exp));
    if (!stack) return;

    for (i = 0, k = -1; exp[i]; ++i) {
       
        if (isOperand(exp[i]))
            exp[++k] = exp[i];

       
        else if (exp[i] == '(')
            push(stack, exp[i]);

        
        else if (exp[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                exp[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return;
            else
                pop(stack);
        }
         else { 
            while (!isEmpty(stack) && precedence(exp[i]) <= precedence(peek(stack)))
                exp[++k] = pop(stack);
            push(stack, exp[i]);
        }
    }

    
    while (!isEmpty(stack))
        exp[++k] = pop(stack);

    exp[++k] = '\0';
    printf("%s\n", exp);
}

int main() {
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    printf("Infix expression: %s\n", exp);
    printf("Postfix expression: ");
    infixToPostfix(exp);
    return 0;
}
        