// Function definitions for CircularList

#include "CircularList.h"
#include <iostream>

using namespace std;

template <typename Type>
void List<Type>::push_back(Type x) {
    ListNode<Type> *newNode;
    newNode = new ListNode<Type>(x, head);
    if (head == NULL) {
        head = newNode;
        head->next = head;
    } else {
        ListNode<Type>* p;
        for (p = head; p->next != head; p = p->next);
        p->next = newNode;
    }
    size++;
}

template <typename Type>
void List<Type>::push_front(Type x) {
    ListNode<Type> *newNode;
    newNode = new ListNode<Type>(x,head);
    if (head == NULL) {
        head = newNode;
        head->next = head;
    } else {
        ListNode<Type>* p;
        for (p = head; p->next != head; p = p->next);
        p->next = newNode;
    }
    head = newNode;
    size++;
}

template <typename Type>
void List<Type>::display() {
    ListNode<Type>* p;
    for (p = head; p->next != head; p = p->next)
        cout << p->val << " ";
    cout << p->val << endl;
}

template <typename Type>
List<Type>::~List() {
    ListNode<Type>* temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        delete (temp);
    }
}