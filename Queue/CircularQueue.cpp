 // Function definitions for Circular Queue
#include "CircularQueue.h"
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
    if ((rear + 1) % size == front)
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
        front = (front + 1) % size;
    }
    return val;
}

template <typename Type>
void Queue<Type>::enqueue(Type x) {
    if (isFull()) {
        std::cout << "OVERFLOW";
        exit(-1);
    }

    if (front == -1) {
        front = rear = 0;
        a[front] = x;
    } else {
        rear = (rear + 1) % size;
        a[rear] = x;
    }
}

template <typename Type>
void Queue<Type>::display() {
    if (isEmpty()) {
        std::cout << "The queue is empty." << std::endl;
    } else {
        for (int i = front ; i != rear; i = (i + 1) % size)
            std::cout << a[i] << " ";
        std::cout << a[rear] << std::endl;
    }
}

template <typename Type>
Queue<Type>::~Queue() {
    delete []a;
}