// To implement a dynamic stack using C

#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    int max;
    int *a;
};

void initialize(struct Stack* stack, int max) {
    stack->top = -1;
    stack->max = max;
    stack->a = (int*)malloc(sizeof(int) * stack->max);
}

void copyStack(int *a, int *b, int n) {
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }
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

void printStack(struct Stack* stack) {
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->a[i]);
    }
}

void upSize(struct Stack* stack) {
    int newMax = stack->max * 2;
    int *temp;
    temp = (int*)malloc(sizeof(int) * stack->max);
    copyStack(stack->a, temp, stack->max);
    free(stack->a);
    stack->a = (int*)malloc(sizeof(int) * newMax);
    copyStack(temp, stack->a, stack->max);
    stack->max = newMax;
    free(temp);
}

void downSize(struct Stack* stack) {
    int newMax = stack->max / 2;
    int *temp;
    temp = (int*)malloc(sizeof(int) * stack->max);
    copyStack(stack->a, temp, stack->max);
    free(stack->a);
    stack->a = (int*)malloc(sizeof(int) * newMax);
    copyStack(temp, stack->a, stack->max);
    stack->max = newMax;
    free(temp);
}

void reSize(struct Stack* stack) {
    if (isFull(stack))
        upSize(stack);
    else if (stack->top < (int)(0.25 * stack->max) - 1)
        downSize(stack);
    else
        return;
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

void menu(struct Stack* stack) {
    int input = 0;
    int x;
    do{
        printf("\n1: Push a number\n");
        printf("2: Pop a number\n");
        printf("3: Get current max size\n");
        printf("4: Print Stack array\n");
        printf("0: EXIT \n");
        printf("Enter your choice -> ");
        scanf("%d", &input);

        switch(input) {
            case 1:
                printf("Enter a number to push -> ");
                scanf("%d", &x);
                push(stack, x);
                reSize(stack);
                break;
            case 2:
                printf("Popped number: %d", pop(stack));
                reSize(stack);
                break;
            case 3:
                printf("Max size: %d", stack->max);
                break;
            case 4:
                printStack(stack);
                break;
            default: break;
        }
    } while(input);
}

int main() {
    struct Stack stack;
    initialize(&stack,2);
    menu(&stack);
    return 0;
}