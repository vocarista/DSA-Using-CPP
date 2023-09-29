// To evaluate a postfix expression using stack

#include "StackArrayCPP.h"
#include "StackArrayCPP.cpp"
#include <iostream>
#include <string>

using namespace std;

int evaluate(int a, int b, char op) {
    switch(op) {
        case '+': return b + a; break;
        case '-': return b - a; break;
        case '*': return b * a; break;
        case '/': return b / a; break;
        case '%': return b % a; break;
        case '^': {
            int res = 1;
            while(a--)
                res *= b;
            return res;
            break;
        }
        default: return -1;break;
    }
}

int main() {
    Stack<int> stack(50);
    string postfix;
    cout << "Rule: Use space to separate different operands and operators, once the expression \nis entered, enter q to terminate input. \n";
    cout << "Enter a postfix expression -> ";
    string cur;
    cin >> cur;
    while (cur != "q"s) {
        if (cur.length() == 1) {
            char c = cur[0];
            if (isdigit(c))
                stack.push(c - 48);
            else {
                int a = stack.pop();
                int b = stack.pop();
                stack.push(evaluate(a, b, c));
            }
        } else {
            stack.push(stoi(cur));
        }
        cin >> cur;
    }

    cout << "The final result is: " << stack.pop();
    return 0;

}