// 1)	WAP to perform addition o f two polynomials using singly linked list.
#include <iostream>
using namespace std;

class Node {
public:
    int coeff;
    int power;
    Node *next;
};

Node *createNode(int c, int p) {
    Node *temp = new Node;
    temp->coeff = c;
    temp->power = p;
    temp->next = NULL;
    return temp;
}

void insertOrdered(Node *&head, int c, int p) {
    if (c == 0) return;
    if (head == NULL || head->power < p) {
        Node *t = createNode(c, p);
        t->next = head;
        head = t;
        return;
    }
    Node *prev = NULL;
    Node *curr = head;
    while (curr && curr->power > p) {
        prev = curr;
        curr = curr->next;
    }
    if (curr && curr->power == p) {
        curr->coeff += c;
        if (curr->coeff == 0) {
            if (prev) prev->next = curr->next;
            else head = curr->next;
            delete curr;
        }
    } else {
        Node *t = createNode(c, p);
        if (prev) {
            prev->next = t;
            t->next = curr;
        } else {
            t->next = head;
            head = t;
        }
    }
}

Node *addPolynomial(Node *head1, Node *head2) {
    Node *t1 = head1;
    Node *t2 = head2;
    Node *result = NULL;
    while (t1 && t2) {
        if (t1->power == t2->power) {
            insertOrdered(result, t1->coeff + t2->coeff, t1->power);
            t1 = t1->next;
            t2 = t2->next;
        } else if (t1->power > t2->power) {
            insertOrdered(result, t1->coeff, t1->power);
            t1 = t1->next;
        } else {
            insertOrdered(result, t2->coeff, t2->power);
            t2 = t2->next;
        }
    }
    while (t1) {
        insertOrdered(result, t1->coeff, t1->power);
        t1 = t1->next;
    }
    while (t2) {
        insertOrdered(result, t2->coeff, t2->power);
        t2 = t2->next;
    }
    return result;
}

void display(Node *head) {
    Node *temp = head;
    if (!temp) {
        cout << "0\n";
        return;
    }
    while (temp) {
        cout << temp->coeff << "x^" << temp->power;
        if (temp->next) cout << " + ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    Node *head_1 = NULL;
    insertOrdered(head_1, 3, 2);
    insertOrdered(head_1, 2, 1);
    insertOrdered(head_1, 3, 1);
    insertOrdered(head_1, 4, 0);
    insertOrdered(head_1, 5, 2);

    Node *head_2 = NULL;
    insertOrdered(head_2, 3, 2);
    insertOrdered(head_2, 2, 1);
    insertOrdered(head_2, 4, 0);

    Node *head3 = addPolynomial(head_1, head_2);
    display(head3);

    return 0;
}

