#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#pragma once

template <typename Type>
class ListNode {
public:
    Type val;
    ListNode* next;
    ListNode(int val): val(val), next(NULL) {}
    ListNode(int val, ListNode* next): val(val), next(next) {}

};

template <typename Type>
class List {
    ListNode<Type>* head;
    int size;
public:
    List();
    void push_back(Type);
    void push_front(Type);
    void push_at(Type, int);
    void display();
    ~List();
};

#endif