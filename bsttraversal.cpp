// 3)  Write a Program to create a Binary Tree and perform the following Recursive
//  operations on it. a. Inorder Traversal b. Preorder Traversal c. Display Number of
//  Leaf Nodes d. Mirror Image
#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *right;
    Node *left;

    Node(int data)
    {
        this->data = data;
        right = nullptr;
        left = nullptr;
    }
};
Node *createNode(int data)
{
    Node *new_node = new Node(data);
}
void preorder(Node *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node *root)
{
    if (root == nullptr)
        return;

    preorder(root->left);
    cout << root->data << " ";
    preorder(root->right);
}
void postorder(Node *root)
{
    if (root == nullptr)
        return;

    preorder(root->left);
    preorder(root->right);
    cout << root->data << " ";
}
void Level_order(Node *root)
{
    if (root == nullptr)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {

        Node *curr = q.front();
        q.pop();

        cout << curr->data << " ";
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}
Node *mirror(Node *root)
{
    if (root == nullptr)
        return nullptr;

    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);

    return root;
}
int main()
{

    // level 1
    Node *root = createNode(10);

    // level 2
    root->left = createNode(5);
    root->right = createNode(20);

    // level 3
    root->left->left = createNode(4);
    root->left->right = createNode(7);
    root->right->left = createNode(15);
    root->right->right = createNode(30);

    cout << "Preorder Traversal : ";
    preorder(root);

    cout << endl
         << "Inorder Traversal : ";
    inorder(root);

    cout << endl
         << "Postorder Traversal : ";
    postorder(root);

    cout << endl
         << "Levelorder Traversal : ";
    Level_order(root);

    return 0;
}
