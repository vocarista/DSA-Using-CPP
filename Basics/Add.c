// To add two numbers

#include <stdio.h>

int main() {
    int x, y;
    printf("Enter two numbers -> ");
    scanf("%d%d", &x, &y);
    int sum = x + y;
    printf("The sum is: %d", sum);
    return 0;
}