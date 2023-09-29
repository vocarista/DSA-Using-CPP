#ifndef STACKARRAYCPP_H
#define STACLARRAYCPP_H
#pragma once

template <typename T>
class Stack {
    T *a;
    int top;
    int max;
public:
    Stack(int max);
    int pop();
    void push(T x);
    bool isEmpty();
    bool isFull();
    ~Stack();
};

#endif