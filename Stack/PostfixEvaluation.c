// To evaluate a postfix evaluation in C


#include "StackArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int getValue(char operator, char operand1, char operand2) {
    int result;
    switch(operator) {
        case '+':
            result = operand2 + operand1;
            break;
        case '-':
            result = operand2 - operand1;
            break;
        case '/':
            result = operand2 / operand1;
            break;
        case '*':
            result = operand2 * operand1;
            break;
        case '%':
            result = operand2 % operand1;
            break;
        default:
            printf("Unexpected error.");
            break;
    }
    return result;
} 

int evaluate(struct Stack* stack, char* exp) {
    int i, op1, op2, result;
    for (i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i]))
            push(stack, exp[i] - 48);
        else {
            op1 = pop(stack);
            op2 = pop(stack);
            result = getValue(exp[i], op1, op2);
            push(stack, result);
        }
    }
    return pop(stack);
}

int main() {
    char exp[80];
    printf("Enter a postfix expression -> ");
    fgets(exp, sizeof(exp), stdin);
    struct Stack stack;
    initialize(&stack, 100);
    int result = evaluate(&stack, exp);
    printf("Result: %d\n", result);
    return 0;
}