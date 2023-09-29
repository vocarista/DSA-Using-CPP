

#include <iostream>
#include "SimpleQueue.h"
#include "SimpleQueue.cpp"

using namespace std;

template <typename Type>
void menu(Queue<Type>& queue) {
    int input = 0;
    int x;
    do{
        printf("\n1: Push a number\n");
        printf("2: Pop a number\n");
        printf("3: Display queue elements\n");
        printf("0: EXIT \n");
        printf("Enter your choice -> ");
        cin >> input;

        switch(input) {
            case 1:
                printf("Enter a number to push -> ");
                cin >> x;
                queue.enqueue(x);
                break;
            case 2:
                cout << "Popped number: " << queue.dequeue();
                break;
            case 3:
                queue.display();
            default: break;
        }
    } while(input);
}

int main() {
    cout << "Enter the size of queue -> ";
    int size;
    cin >> size;
    Queue<int> queue(size);
    menu(queue);
    return 0;
}