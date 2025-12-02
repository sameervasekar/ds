// 3) Implement Bubble sort using Doubly Linked List
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
};
void Bubblesort(Node *&head)
{
    if (head == NULL)
        return;

    bool swapped;
    Node *ptr;

    do
    {
        swapped = false;
        ptr = head;

        while (ptr->next)
        {
            if (ptr->data > ptr->next->data)
            {

                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = true;
            }
            ptr = ptr->next;
        }
    } while (swapped);
}
void display(Node *&head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " -- ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main()
{

    Node *head = new Node(1);
    Node *n2 = new Node(5);
    Node *n3 = new Node(2);
    Node *n4 = new Node(4);
    Node *n5 = new Node(3);

    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    n2->prev = head;
    n3->prev = n2;
    n4->prev = n3;
    n5->prev = n4;

    display(head);
    Bubblesort(head);

    display(head);

    return 0;
}
