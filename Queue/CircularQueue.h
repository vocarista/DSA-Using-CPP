#ifndef SIMPLEQUEUE_H
#define SIMPLEQUEUE_H
#pragma once

template <typename Type>
class Queue {
    Type *a;
    int front;
    int rear;
    int size;
public:
    Queue(int);
    void enqueue(Type);
    Type dequeue();
    bool isEmpty();
    bool isFull();
    void display();
    ~Queue();
};

#endif