// To implement a basic stack using C

#include "StackArray.h"
#include <stdio.h>
#include <stdlib.h>

void initialize(struct Stack* stack, int max) {
    stack->a = (int*)malloc(sizeof(int) * max);
    stack->top = -1;
    stack->max = max;
}

int isEmpty(struct Stack* stack) {
    if (stack->top == -1) {
        return 1;
    }
    return 0;
}

int isFull(struct Stack* stack) {
    if(stack->top == stack->max - 1) {
        return 1;
    }

    return 0;
}

void push(struct Stack* stack, int x) {
    if (isFull(stack)) {
        printf("OVERFLOW!!!");
        exit(-1);
    }

    stack->a[++stack->top] = x;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("UNDERFLOW!!!");
        exit(-1);
    }

    return stack->a[stack->top--];
}
