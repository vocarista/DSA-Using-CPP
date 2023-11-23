// Main for CircularList

#include <iostream>
#include "CircularList.h"
#include "CircularList.cpp"

using namespace std;

template <typename Type>
void menu(List<Type> list) {
    int input = 0;
    Type x;
    do{
        printf("\n1: Push a number at front\n");
        printf("2: Push a number at back\n");
        printf("3: Display all elements\n");
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
                list.display();
            case 0: break;
            default: break;
        }
    } while(input);
}

int main() {
    List<int> list;
    menu(list);
    return 0;
}