#include "StackArrayCPP.h"
#include <iostream>

template <typename T>
Stack<T>::Stack(int max) {
    top = -1;
    this->max = max;
    a = new int[max];
}

template <typename T>
bool Stack<T>::isEmpty() {
    if (top == -1)
        return true;
    return false;
}

template <typename T>
bool Stack<T>::isFull() {
    if (top == max - 1)
        return true;
    return false;
}

template <typename T>
int Stack<T>::pop() {
    if(isEmpty()) {
        std::cout << "UNDERFLOW";
        exit(-1);
    }
    return a[top--];
}

template <typename T>
void Stack<T>::push(T x) {
    if (isFull()) {
        std::cout << "OVERFLOW";
        exit(-1);
    }

    a[++top] = x;
}

template <typename T>
Stack<T>::~Stack() {
    delete []a;
}