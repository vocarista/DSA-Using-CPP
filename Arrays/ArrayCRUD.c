// To create and print an array in C

#include <stdio.h>

void createArray(int* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter a number -> ");
        scanf("%d", a + i);
    }
}

void printArray(int *a, int n) {
    printf("Elements in array: \n");
    printf("Index\t\tElement\n");
    for (int i = 0; i < n; i++)
        printf("%d\t\t%d\n",i, a[i]);
}

void insertElement(int *a, int *n, int val, int index) {
    int i;
    if (index < 0) {
        printf("Invalid index!");
        return;
    }
    for (i = (*n)-1; i >= 0 && i >= index; i--)
        a[i + 1] = a[i];
    a[index] = val;
    (*n)++;
}

void deleteElement(int *a, int *n, int index) {
    int i;
    if (index < 0) {
        printf("Invalid index!");
        return;
    }
    for (i = index; i < (*n); i++)
        a[i] = a[i + 1];
    (*n)--;
}

void menu(int *a, int n) {
    int input = 0;
    int x, index;
    do{
        printf("\n1: Create the array\n");
        printf("2: Print the array\n");
        printf("3: Print Number of elements\n");
        printf("4: Insert an element\n");
        printf("5: Delete an element\n");
        printf("0: EXIT\n");
        printf("Enter your choice -> ");
        scanf("%d", &input);

        switch(input) {
            case 1:
                createArray(a, n);
                break;
            case 2:
                printArray(a, n);
                break;
            case 3:
                printf("Number of elements: %d", n);
                break;
            case 4:
                printf("Enter the element and index for insertion -> ");
                scanf("%d%d", &x, &index);
                insertElement(a, &n, x, index);
                break;
            case 5:
                printf("Enter the index from where the element is to be deleted -> ");
                scanf("%d", &index);
                deleteElement(a, &n, index);
                break;
            default: break;
        }
    } while(input);
}

int main() {
    int n, a[100];
    printf("Enter the number of elements in the array -> ");
    scanf("%d", &n);
    menu(a, n);
    return 0;
}