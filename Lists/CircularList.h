#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H
#pragma once

template <typename Type>
class ListNode {
    public:
    Type val;
    ListNode* next;
    ListNode(Type val): val(val), next(NULL) {}
    ListNode(Type val, ListNode* next): val(val), next(next){}
};

template <typename Type>
class List {
    ListNode<Type>* head;
    int size;
    public:
    List(): head(NULL), size(0){}
    void push_back(Type);
    void push_front(Type);
    void display();
    ~List();
};

#endif