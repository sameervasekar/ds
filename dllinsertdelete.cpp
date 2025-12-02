// 2) WAP to create a doubly linked list and perform following operations on it.A) Insert (all cases) 2. Delete (all cases).
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* createNode(int v) {
    Node* p = new Node;
    p->data = v;
    p->prev = NULL;
    p->next = NULL;
    return p;
}

void insertAtBeginning(Node*& head, Node*& tail, int v) {
    Node* n = createNode(v);
    if (head == NULL) {
        head = tail = n;
        return;
    }
    n->next = head;
    head->prev = n;
    head = n;
}

void insertAtEnd(Node*& head, Node*& tail, int v) {
    Node* n = createNode(v);
    if (tail == NULL) {
        head = tail = n;
        return;
    }
    tail->next = n;
    n->prev = tail;
    tail = n;
}

void insertAtPosition(Node*& head, Node*& tail, int pos, int v) {
    if (pos <= 1) {
        insertAtBeginning(head, tail, v);
        return;
    }
    Node* cur = head;
    int i = 1;
    while (cur != NULL && i < pos) {
        cur = cur->next;
        i++;
    }
    if (cur == NULL) { // insert at end
        insertAtEnd(head, tail, v);
        return;
    }
    Node* n = createNode(v);
    Node* prev = cur->prev;
    prev->next = n;
    n->prev = prev;
    n->next = cur;
    cur->prev = n;
}

void deleteAtBeginning(Node*& head, Node*& tail) {
    if (head == NULL) return;
    Node* t = head;
    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    delete t;
}

void deleteAtEnd(Node*& head, Node*& tail) {
    if (tail == NULL) return;
    Node* t = tail;
    if (head == tail) {
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    delete t;
}

void deleteAtPosition(Node*& head, Node*& tail, int pos) {
    if (head == NULL) return;
    if (pos <= 1) {
        deleteAtBeginning(head, tail);
        return;
    }
    Node* cur = head;
    int i = 1;
    while (cur != NULL && i < pos) {
        cur = cur->next;
        i++;
    }
    if (cur == NULL) return;
    if (cur == tail) {
        deleteAtEnd(head, tail);
        return;
    }
    Node* p = cur->prev;
    Node* q = cur->next;
    p->next = q;
    q->prev = p;
    delete cur;
}

void displayForward(Node* head) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    Node* cur = head;
    while (cur != NULL) {
        cout << cur->data;
        if (cur->next) cout << " <-> ";
        cur = cur->next;
    }
    cout << "\n";
}

void displayBackward(Node* tail) {
    if (tail == NULL) {
        cout << "List is empty\n";
        return;
    }
    Node* cur = tail;
    while (cur != NULL) {
        cout << cur->data;
        if (cur->prev) cout << " <-> ";
        cur = cur->prev;
    }
    cout << "\n";
}

void freeList(Node*& head) {
    Node* cur = head;
    while (cur != NULL) {
        Node* t = cur;
        cur = cur->next;
        delete t;
    }
    head = NULL;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int ch;
    while (1) {
        cout << "\n1.Insert at beginning\n2.Insert at end\n3.Insert at position\n4.Delete at beginning\n5.Delete at end\n6.Delete at position\n7.Display forward\n8.Display backward\n9.Exit\nChoose: ";
        if (!(cin >> ch)) break;
        if (ch == 1) {
            int v; cout << "Value: "; cin >> v;
            insertAtBeginning(head, tail, v);
        } else if (ch == 2) {
            int v; cout << "Value: "; cin >> v;
            insertAtEnd(head, tail, v);
        } else if (ch == 3) {
            int v, p; cout << "Value: "; cin >> v; cout << "Position: "; cin >> p;
            insertAtPosition(head, tail, p, v);
        } else if (ch == 4) {
            deleteAtBeginning(head, tail);
        } else if (ch == 5) {
            deleteAtEnd(head, tail);
        } else if (ch == 6) {
            int p; cout << "Position: "; cin >> p;
            deleteAtPosition(head, tail, p);
        } else if (ch == 7) {
            displayForward(head);
        } else if (ch == 8) {
            displayBackward(tail);
        } else if (ch == 9) {
            break;
        } else {
            cout << "Invalid choice\n";
        }
    }
    freeList(head);
    return 0;
}

