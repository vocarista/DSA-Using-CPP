 // Program to show the workings of tower of hanoi

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
class Stack{
    int *a;
    int top;
    int max;
public:
    std::string name;
    Stack(int max, std::string name) {
        this->max = max;
        this->name = name;
        this->top = -1;
        a = new int[this->max];
    }

    bool isEmpty() {
        if (top == -1) {
            return true;
        }
        return false;
    }

    bool isFull() {
        if(top == max - 1) {
            return true;
        }

        return false;
    }

    void push(int x) {
        if (isFull()) {
            std::cout << "OVERFLOW";
            exit(-1);
        }

        a[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "UNDERFLOW!!!";
            exit(-1);
        }

        return a[top--];
    }

    int getTop() {
        if (isEmpty())
            return -1;
        return a[top];
    }

    ~Stack() {
        delete []a;
    }

};

void toi(int n, Stack& src, Stack& aux, Stack& dest) {
    if (n > 0) {
        toi(n - 1, src, dest, aux);
        dest.push(src.pop());
        std::cout << src.name << " -> " << dest.name << std::endl;
        toi(n - 1, aux, src, dest);
    }

    return;
}

int main() {
    int n;
    std::cout << "Enter the number of disks -> ";
    std::cin >> n;
    Stack src(n, "A"s), aux(n, "B"s), dest(n, "C"s);
    for(int i = n; i > 0; i--) {
        src.push(i);
    }

    toi(n, src, aux, dest);

    while(!dest.isEmpty())
        cout << dest.pop() << endl;

    return 0;
}