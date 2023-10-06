// Function definitions for singly linked list

#include <iostream>
#include "DoublyList.h"

template <typename Type>
List<Type>::List() {
    head = NULL;
    this->size = 0;
}

template <typename Type>
void List<Type>::push_back(Type x) {
    ListNode<Type>* newNode;
    newNode = new ListNode<Type>(x);
    if (newNode == NULL) {
        std::cout << "OVERFLOW";
        exit(-1);
    }

    if (head == NULL)
        head = newNode;
    else {
        ListNode<Type>* p;
        for (p = head; p->next != NULL; p = p->next);
        p->next = newNode;
        newNode->prev = p;
    }
    size++;
}

template <typename Type>
void List<Type>::push_front(Type x) {
    ListNode<Type>* newNode;
    newNode = new ListNode<Type>(x, head);
    if (newNode == NULL) {
        std::cout << "OVERFLOW";
        exit(-1);
    }
    if (head == NULL) {
        head = newNode;
        return;
    }
    newNode->prev = NULL;
    head = newNode;
}

template <typename Type>
void List<Type>::push_at(Type x, int loc) {
    ListNode<Type>* newNode;
    newNode = new ListNode<Type>(x);
    if (newNode == NULL) {
        std::cout << "OVERFLOW";
        exit(-1);
    }
    if (head == NULL) {
        head = newNode;
    } else {
        ListNode<Type>* p = head;
        for (int i = 1; i < loc - 1; i++, p = p->next);
        newNode->next = p->next;
        newNode->prev = p;
        p->next->prev = newNode;
        p->next = newNode;
    }
    size++;
}

template <typename Type>
void List<Type>::display() {
    if (head == NULL) {
        std::cout << "The list is empty.";
        return;
    }
    
    ListNode<Type>* temp;
    for (temp = head; temp != NULL; temp = temp->next) {
        std::cout << temp->val << " ";
    }
}

template <typename Type>
void List<Type>::display_rev() {
    if (head == NULL) {
        std::cout << "The list is empty.";
        return;
    }
    ListNode<Type>* p;
    for (p = head; p->next != NULL; p = p->next);
    for (; p != NULL; p = p->prev)
        std::cout << p->val << " ";
}

template <typename Type>
List<Type>::~List() {
    ListNode<Type>* temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        delete(temp);
    }
}