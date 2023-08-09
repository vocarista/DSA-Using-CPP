// To implement a sparse matrix using a linked list in C

#include <stdio.h>
#include <stdlib.h>

struct Element {
    int data;
    int row;
    int col;
    struct Element* next;
};

struct SparseMatrix {
    struct Element* elements;
    int rows;
    int cols;
    int noe;
};

void initialize(struct SparseMatrix* matrix, int rows, int cols) {
    matrix->elements = NULL;
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->noe = 0;
}

void insertElement(struct SparseMatrix* matrix, int value, int row, int col) {
    struct Element* p;
    p = (struct Element*)malloc(sizeof(struct Element));
    p->data = value;
    p->row = row;
    p->col = col;
    p->next = NULL;
    if (matrix->elements == NULL)
        matrix->elements = p;
    else {
        struct Element* q;
        for (q = matrix->elements; q->next != NULL; q = q->next);
        q->next = p;
    }
    matrix->noe++;
}

void deleteElement(struct SparseMatrix* matrix, int value) {
    struct Element *q, *r;
    if (matrix->elements->data == value) {
        q = matrix->elements;
        matrix->elements = matrix->elements->next;
        free(q);
        matrix->noe--;
        return;
    } else {
        for (q = matrix->elements; q != NULL && q->data != value; q = q->next)
            r = q;
    }
    if (q == NULL) {
        printf("Element not found.");
        return;
    }
    r->next = q->next;
    matrix->noe--;
    free(q);
}

void readMatrix(struct SparseMatrix* matrix) {
    int x, i, j;
    for (i = 0; i < matrix->rows; i++) {
        for (j = 0; j < matrix->cols; j++) {
            printf("Enter a number -> ");
            scanf("%d", &x);
            if (x != 0)
                insertElement(matrix, x, i, j);
        }
    }
}

void printMatrix(struct SparseMatrix* matrix) {
    int i, j;
    struct Element *p = matrix->elements;
    for (i = 0; i < matrix->rows; i++) {
        printf("\n");
        for (j = 0; j < matrix->cols; j++) {
            if (p != NULL && p->row == i && p->col == j) {
                printf("%d ", p->data);
                p = p->next;
            }
            else
                printf("%d ", 0);
        }
    }
}

void printList(struct SparseMatrix* matrix) {
    struct Element* p;
    for (p = matrix->elements; p != NULL; p = p->next)
        printf("%d ", p->data);
}

void menu(struct SparseMatrix* matrix) {
    int input = 0;
    int x;
    do{
        printf("\n1: Read Matrix\n");
        printf("2: Print Matrix\n");
        printf("3: Get number of elements\n");
        printf("4: Print flattened list\n");
        printf("5: Delete an element\n");
        printf("0: EXIT \n");
        printf("Enter your choice -> ");
        scanf("%d", &input);

        switch(input) {
            case 1:
                readMatrix(matrix);
                break;
            case 2:
                printMatrix(matrix);
                break;
            case 3:
                printf("Number of elements: %d", matrix->noe);
                break;
            case 4:
                printList(matrix);
                break;
            case 5:
                printf("Enter the number to be deleted -> ");
                scanf("%d", &x);
                deleteElement(matrix, x);
            default: break;
        }
    } while(input);
}

int main() {
    struct SparseMatrix matrix;
    int m, n;
    printf("Enter the number of rows and columns -> ");
    scanf("%d%d", &m, &n);
    initialize(&matrix, m, n);
    menu(&matrix);
    return 0;
}
