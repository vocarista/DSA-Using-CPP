// Main for Singly Linked List

#include <iostream>
#include "DoublyList.h"
#include "DoublyList.cpp"

using namespace std;

template <typename Type>
void menu(List<Type> list) {
    int input = 0;
    Type x;
    do{
        printf("\n1: Push a number at front\n");
        printf("2: Push a number at back\n");
        printf("3: Push a number at a specific location\n");
        printf("4: Display all elements\n");
        printf("5: Display all elements in reverse order \n");
        printf("0: EXIT \n");
        printf("Enter your choice -> ");
        cin >> input;

        switch(input) {
            case 1:
                printf("Enter a number to push -> ");
                cin >> x;
                list.push_front(x);
                list.display();
                break;
            case 2:
                printf("Enter a number to push -> ");
                cin >> x;
                list.push_back(x);
                list.display();
                break;
            case 3:
                printf("Enter a number and a position to push at -> ");
                int loc;
                cin >> x >> loc;
                list.push_at(x, loc);
                list.display();
                break;
            case 4:
                list.display();
                break;
            case 5:
                list.display_rev();
            default: break;
        }
    } while(input);
}

int main() {
    List<int> list;
    menu(list);
    return 0;
}