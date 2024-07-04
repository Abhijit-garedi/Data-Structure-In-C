//Develop and Implement a Program in C for converting an Infix Expression to Postfix
// Expression. Program should support for both parenthesized and free parenthesized expressions
// with the operators: +, -, *, /, %(Remainder), ^(Power) and alphanumeric operands.


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