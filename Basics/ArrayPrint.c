// Array traversing

#include <stdio.h>
#include <stdlib.h>

void read(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter a number -> ");
        scanf("%d", &a[i]);
    }
}

void print(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

int main() {
    int *a, n;
    printf("Enter the number of elements in the array -> ");
    scanf("%d", &n);
    a = (int*)malloc(sizeof(int) * n);
    read(a, n);
    print(a, n);
    free(a);
    return 0;

    // int a[1];
    // read(a, 10);
    // print(a, 10);
    // return 0;
}