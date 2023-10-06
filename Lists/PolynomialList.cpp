// To implement a polynomial using linked list

#include <iostream>
#include <stdlib.h>

using namespace std;

class PolyNode{
public:
    double coef;
    int degree;
    PolyNode* next;
    PolyNode (double coef, int degree): coef(coef), degree(degree), next(NULL) {}
};

class Polynomial {
    PolyNode* head;
public:
    Polynomial(): head(NULL) {}
    void createPoly();
    void push_back(int coef, int deg);
    Polynomial operator*(const Polynomial&);
    Polynomial operator+(const Polynomial&);
    void display();
};

void Polynomial::createPoly() {
    int n;
    cout << "Enter the number of terms -> ";
    cin >> n;
    while(n--) {
        int temp_deg;
        double temp_coef;
        cout << "Enter the coeficient and the degree of the term -> ";
        cin >> temp_coef >> temp_deg;
        push_back(temp_coef, temp_deg);
    }   
}

void Polynomial::display() {
    PolyNode* p;
    for (p = head; p != NULL; p = p->next) {
        cout << "+" << p->coef << "x^" << p->degree;
    }
}

Polynomial Polynomial::operator+(const Polynomial& poly) {
    PolyNode* p;
    PolyNode* q;
    p = head;
    q = poly.head;
    Polynomial sum;
    while(p != NULL && q != NULL) {
        if (p->degree == q->degree) {
            sum.push_back(p->coef + q->coef, p->degree);
            p = p->next;
            q = q->next;
        } else if (p->degree > q->degree) {
            sum.push_back(p->coef, p->degree);
            p = p->next;
        } else {
            sum.push_back(q->coef, q->degree);
            q = q->next;
        }
    }

    while(p != NULL) {
        sum.push_back(p->coef, p->degree);
        p = p->next;
    }

    while(q != NULL){
        sum.push_back(q->coef, q->degree);
        q = q->next;
    }

    return sum;
}

Polynomial Polynomial::operator*(const Polynomial& poly) {
    PolyNode* p;
    PolyNode* q;
    
}