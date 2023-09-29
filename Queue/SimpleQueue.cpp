#include "SimpleQueue.h"
#include <iostream>

template <typename Type>
Queue<Type>::Queue(int size) {
    front = rear = -1;
    a = new Type[size];
    this->size = size;
}

template <typename Type>
bool Queue<Type>::isEmpty() {
    if (front == -1)
        return true;
    return false;
}

template <typename Type>
bool Queue<Type>::isFull() {
    if (rear == size - 1)
        return true;
    return false;
}

template <typename Type>
Type Queue<Type>::dequeue() {
    if (isEmpty()) {
        std::cout << "UNDERFLOW";
        exit(-1);
    }

    Type val;
    if (front == rear) {
        val = a[front];
        front = rear = -1;
    } else {
        val = a[front];
        front++;
    }

    return val;
}

template <typename Type>
void Queue<Type>::enqueue(Type x) {
    if (isFull()) {
        std::cout << "OVERFLOW";
        exit(-1);
    }

    if (rear == -1) {
        front = rear = 0;
        a[rear] = x;
    } else {
        a[++rear] = x;
    }
}

template <typename Type>
void Queue<Type>::display() {
    for(int i = front; i <= rear; i++) {
        std::cout << a[i] << " ";
    }
}

template <typename Type>
Queue<Type>::~Queue() {
    delete []a;
}