#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int pow;
    Node* next;
};


Node* createNode(int coeff, int pow) {
    Node* newNode = new Node;
    (*newNode).coeff = coeff;
    (*newNode).pow = pow;
    (*newNode).next = NULL;
    return newNode;
}


void insert(Node*& poly, int coeff, int pow) {
    Node* newNode = createNode(coeff, pow);

    if (poly == NULL) {
        poly = newNode;
    } else {
        Node* temp = poly;
        while ((*temp).next != NULL) {
            temp = (*temp).next;
        }
        (*temp).next = newNode;
    }
}


Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* t1 = poly1;
    Node* t2 = poly2;

    while (t1 != NULL && t2 != NULL) {
        if ((*t1).pow == (*t2).pow) {
            insert(result, (*t1).coeff + (*t2).coeff, (*t1).pow);
            t1 = (*t1).next;
            t2 = (*t2).next;
        } else if ((*t1).pow > (*t2).pow) {
            insert(result, (*t1).coeff, (*t1).pow);
            t1 = (*t1).next;
        } else {
            insert(result, (*t2).coeff, (*t2).pow);
            t2 = (*t2).next;
        }
    }

    while (t1 != NULL) {
        insert(result, (*t1).coeff, (*t1).pow);
        t1 = (*t1).next;
    }
    while (t2 != NULL) {
        insert(result, (*t2).coeff, (*t2).pow);
        t2 = (*t2).next;
    }

    return result;
}


void display(Node* poly) {
    Node* temp = poly;
    while (temp != NULL) {
        cout << (*temp).coeff << "x^" << (*temp).pow;
        if ((*temp).next != NULL) cout << " + ";
        temp = (*temp).next;
    }
    cout << endl;
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    Node* sum = NULL;

    int n1, n2, coeff, pow;

    cout << "Enter number of terms in Polynomial 1: ";
    cin >> n1;
    cout << "Enter terms (coeff power) in decreasing order of power:\n";
    for (int i = 0; i < n1; i++) {
        cin >> coeff >> pow;
        insert(poly1, coeff, pow);
    }

    cout << "Enter number of terms in Polynomial 2: ";
    cin >> n2;
    cout << "Enter terms (coeff power) in decreasing order of power:\n";
    for (int i = 0; i < n2; i++) {
        cin >> coeff >> pow;
        insert(poly2, coeff, pow);
    }

    cout << "\nPolynomial 1: ";
    display(poly1);

    cout << "Polynomial 2: ";
    display(poly2);

    sum = addPolynomials(poly1, poly2);

    cout << "Sum: ";
    display(sum);

    return 0;
}

