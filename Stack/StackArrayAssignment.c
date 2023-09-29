/**
 * Author: Kumar Piyush (vocarista)
 * Created: 25-08-2023
 * Tags: Stack, String, Pointers
*/

#include <stdio.h>
#include <stdlib.h>

struct Stack {
    char *a;
    int top;
    int max;
};

void initialize(struct Stack* stack, int max) {
    stack->a = (char*)malloc(sizeof(char) * max);
    stack->max = max;
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    if (stack->top == -1) {
        return 1;
    }
    return 0;
}

int isFull(struct Stack* stack) {
    if(stack->top == stack->max - 1) {
        return 1;
    }

    return 0;
}

void push(struct Stack* stack, int x) {
    if (isFull(stack)) {
        printf("OVERFLOW!!!");
        exit(-1);
    }

    stack->a[++stack->top] = x;
}

char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("UNDERFLOW!!!");
        exit(-1);
    }

    return stack->a[stack->top--];
}

int getLength(char *a) {
    int length = 0;
    for (int i = 0; a[i] != '\0'; i++)
        length++;
    return length;
}

int isPalindrome(char *a) {
    struct Stack stack;
    int length = getLength(a);
    initialize(&stack, length);

    for (int i = 0; a[i] != '\0'; i++)
        push(&stack, a[i]);

    for (int i = 0; a[i] != '\0' && a[i] == pop(&stack); i++);
    if (isEmpty(&stack))
        return 1;
    else
        return 0;

}

int main() {
    struct Stack stack;
    initialize(&stack, 100);
    char x;
    // // --------------------- Demonstrate push ----------------------------------//
    // printf("Enter a character to push -> ");
    // scanf("%c", &x);
    // push(&stack, x);
    
    // // --------------------- Demonstrate pop ---------------------------------- //

    // printf("Popped value: %c", pop(&stack));

    // --------------------- Push and Pop together ---------------------------- //

    // int n;
    // printf("Enter the number of values to push -> ");
    // scanf("%d", &n);
    // fflush(stdin);

    // for(int i = 0; i < n; i++) {
    //     printf("Enter a character -> ");
    //     scanf("%c", &x);
    //     fflush(stdin);
    //     push(&stack, x);
    // }
 
    // printf("\nPopped values: ");
    // while(!isEmpty(&stack))
    //     printf("%c ", pop(&stack));

    // -------------------- Check Palindrome --------------------------------- //

    // char a[80];
    // printf("Enter a string -> ");
    // gets(a);

    // if (isPalindrome(a))
    //     printf("The string is a palindrome");
    // else
    //     printf("The string is not a palindrome");
    
    // // -------------------- Print the elements and get the max size --------- //

    // int n;
    // printf("Enter the number of values to push -> ");
    // scanf("%d", &n);
    // fflush(stdin);

    // for(int i = 0; i < n; i++) {
    //     printf("Enter a character -> ");
    //     scanf("%c", &x);
    //     fflush(stdin);
    //     push(&stack, x);
    // }

    // printf("The elements of the stack are: ");
    // for (int i = 0; i < n; i++)
    //     printf("%c, ", stack.a[i]);
    
    // printf("The number of elements in the stack are: %d", stack.top + 1);
    
    // ----------------------------------------------------------------------- //

    return 0;
}