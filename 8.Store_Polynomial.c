#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int coefficient, int exponent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

Node* addTerm(Node* poly, int coefficient, int exponent) {
    Node* term = createNode(coefficient, exponent);

    if (poly == NULL) {
        return term;
    }

    Node* current = poly;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = term;
    return poly;
}

Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;

    while (poly1 != NULL || poly2 != NULL) {
        int coeff1 = (poly1 != NULL) ? poly1->coefficient : 0;
        int exp1 = (poly1 != NULL) ? poly1->exponent : 0;

        int coeff2 = (poly2 != NULL) ? poly2->coefficient : 0;
        int exp2 = (poly2 != NULL) ? poly2->exponent : 0;

        int sum_coeff = coeff1 + coeff2;
        result = addTerm(result, sum_coeff, exp1);

        if (poly1 != NULL) {
            poly1 = poly1->next;
        }
        if (poly2 != NULL) {
            poly2 = poly2->next;
        }
    }

    return result;
}

void displayPolynomial(Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d ", poly->coefficient, poly->exponent);
        poly = poly->next;
        if (poly != NULL) {
            printf("+ ");
        }
    }
    printf("\n");
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    Node* result = NULL;

    poly1 = addTerm(poly1, 5, 2);
    poly1 = addTerm(poly1, -3, 1);
    poly1 = addTerm(poly1, 2, 0);

    poly2 = addTerm(poly2, 4, 3);
    poly2 = addTerm(poly2, 1, 1);
    poly2 = addTerm(poly2, -7, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    result = addPolynomials(poly1, poly2);

    printf("Sum of Polynomials: ");
    displayPolynomial(result);

    return 0;
}
