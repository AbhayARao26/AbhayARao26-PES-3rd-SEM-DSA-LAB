/*
 Polynomial Addition
 
    You are given two polynomials represented as linked lists. Each node in the linked list represents a term in the polynomial, with the coefficient and exponent of that term. Your task is to write a C program to add these two polynomials and return the resultant polynomial as a linked list.

 Input Format

 First line of input contains n and m number of terms in the polynomial
 the next ‘n + m’ lines contain the coefficient and the power
 the highest order terms come first , and then the lower order terms
 Constraints

 None

 Output Format

 Print the coefficients of the polynomial in the order of highest degree to lowest
 Sample Input 0

 2 2
 3 4
 2 3
 4 3
 1 2
 Sample Output 0

 3 6 1
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int pow;
    struct Node *next;
} Node;

Node *create_node(int coeff, int pow) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->coeff = coeff;
    node->pow = pow;
    node->next = NULL;
    return node;
}

void insert_node(Node **head, int coeff, int pow) {
    Node *node = create_node(coeff, pow);
    if (*head == NULL) {
        *head = node;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
}

void print_list(Node *head) {
    while (head != NULL) {
        printf("%d ", head->coeff);
        head = head->next;
    }
}

Node *add_polynomials(Node *p1, Node *p2) {
    Node *result = NULL;
    while (p1 != NULL && p2 != NULL) {
        if (p1->pow > p2->pow) {
            insert_node(&result, p1->coeff, p1->pow);
            p1 = p1->next;
        } else if (p1->pow < p2->pow) {
            insert_node(&result, p2->coeff, p2->pow);
            p2 = p2->next;
        } else {
            insert_node(&result, p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        insert_node(&result, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        insert_node(&result, p2->coeff, p2->pow);
        p2 = p2->next;
    }
    return result;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    Node *p1 = NULL;
    for (int i = 0; i < n; i++) {
        int coeff, pow;
        scanf("%d %d", &coeff, &pow);
        insert_node(&p1, coeff, pow);
    }
    
    Node *p2 = NULL;
    for (int i = 0; i < m; i++) {
        int coeff, pow;
        scanf("%d %d", &coeff, &pow);
        insert_node(&p2, coeff, pow);
    }
    
    Node *result = add_polynomials(p1, p2);
    
    print_list(result);

    return 0;
}
