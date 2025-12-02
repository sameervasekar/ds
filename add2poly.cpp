// 1)	WAP to perform addition o f two polynomials using singly linked list.
#include <iostream>
using namespace std;
class Node
{
public:
    int coeff;
    int power;
    Node *next;
};
Node *createNode(int c, int p)
{
    Node *temp = new Node;
    temp->coeff = c;
    temp->power = p;
    temp->next = NULL;
    return temp;
}
void insertNode(Node *&head, int c, int p)
{
    if (head == NULL)
    {
        head = createNode(c, p);
        return;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    Node *newNOde = createNode(c, p);
    temp->next = newNOde;

    return;
}
Node *addPolyNomial(Node *&head_1, Node *&head_2)
{
    Node *temp_1 = head_1;
    Node *temp_2 = head_2;
    Node *result = NULL;

    while (temp_1 && temp_2)
    {
        if (temp_1->power == temp_2->power)
        {
            insertNode(result, temp_1->coeff + temp_2->coeff, temp_1->power);
            temp_2 = temp_2->next;
            temp_1 = temp_1->next;
        }
        else if (temp_1->power > temp_2->power)
        {
            insertNode(result, temp_1->coeff, temp_1->power);
            temp_1 = temp_1->next;
        }
        else if (temp_2->power > temp_1->power)
        {
            insertNode(result, temp_2->coeff, temp_2->power);
            temp_2 = temp_2->next;
        }
    }

    while (temp_1)
    {
        insertNode(result, temp_1->coeff, temp_1->power);
        temp_1 = temp_1->next;
    }

    while (temp_2)
    {
        {
            insertNode(result, temp_2->coeff, temp_2->power);
            temp_2 = temp_2->next;
        }
    }
    return result;
}
void display(Node *&head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->coeff << "x^" << temp->power;
        if (temp->next)
            cout << " + ";
        temp = temp->next;
    }
}
int main()
{
    Node *head_1 = createNode(3, 2);
    insertNode(head_1, 2, 1);
    insertNode(head_1, 3, 1);
    insertNode(head_1, 4, 0);
    insertNode(head_1, 5, 2);

    Node *head_2 = createNode(3, 2);
    insertNode(head_2, 2, 1);
    insertNode(head_2, 4, 0);

    Node *head3 = addPolyNomial(head_1, head_2);
    display(head3);

    return 0;
}
