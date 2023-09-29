#ifndef STACKARRAY_H
#define STACKARRAY_H
#pragma once

struct Stack {
    int *a;
    int top;
    int max;
};

void initialize(struct Stack* stack, int max);
int isEmpty(struct Stack* stack);
int isFull(struct Stack* stack);
void push(struct Stack* stack, int x);
int pop(struct Stack* stack);

#endif
