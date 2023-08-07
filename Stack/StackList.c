// To implement a stack using linked lists in C

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node *top;
    int max;
};

void initialize(struct Stack* stack, int max) {
    stack->top = NULL;
    stack->max = max;
}

int isFull(struct Stack* stack) {
    int count = 0;
    struct Node* p = stack->top;
    while(p != NULL) {
        count++;
        p = p->next;
    }
    if (count == stack->max)
        return 1;
    else
        return 0;
}

int isEmpty(struct Stack* stack) {
    if (stack->top == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void push(struct Stack* stack, int x) {
    if (isFull(stack)) {
        printf("OVERFLOW!!!");
        exit(1);
    }
    struct Node* p;
    p = (struct Node*)malloc(sizeof(struct Node));
    p->data = x;
    p->next = NULL;
    
    if (stack->top == NULL) {
        stack->top = p;
    } else {
       p->next = stack->top;
       stack->top = p;
    }
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("UNDERFLOW!!!");
        exit(1);
    }
    int x = stack->top->data;
    struct Node* p = stack->top;

    if (stack->top->next == NULL) {
        stack->top = NULL;
    } else {
        stack->top = stack->top->next;
    }
    free(p);
    return x;
}

void printStack(struct Stack* stack) {
    for (struct Node* p = stack->top; p != NULL; p = p->next) {
        printf("%d ", p->data);
    }
}

void menu(struct Stack* stack) {
    int input = 0;
    int x;
    do{
        printf("\n1: Push a number\n");
        printf("2: Pop a number\n");
        printf("3: Print Stack List\n");
        printf("0: EXIT \n");
        printf("Enter your choice -> ");
        scanf("%d", &input);

        switch(input) {
            case 1:
                printf("Enter a number to push -> ");
                scanf("%d", &x);
                push(stack, x);
                break;
            case 2:
                printf("Popped number: %d", pop(stack));
                break;
            case 3:
                printStack(stack);
                break;
            default: break;
        }
    } while(input);
}

int main() {
    struct Stack stack;
    int max;
    printf("Enter the maximum capacity of the stack -> ");
    scanf("%d", &max);
    initialize(&stack, max);
    menu(&stack);
    return 0;
}