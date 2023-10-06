#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#pragma once

template <typename Type>
class ListNode {
public:
    Type val;
    ListNode *prev;
    ListNode* next;
    ListNode(int val): val(val), next(NULL), prev(NULL) {}
    ListNode(int val, ListNode* next): val(val), next(next), prev(NULL) {}

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
    void display_rev();
    ~List();
};

#endif