// 1) Write a program to perform Binary Search Tree (BST) operations (Create, Insert,
// Delete, Levelwise  display )
#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

Node* createNode(int data) {
    return new Node(data);
}

Node* Insert(Node* root, int key) {
    if (root == nullptr)
        return createNode(key);

    if (key < root->data)
        root->left = Insert(root->left, key);
    else if (key > root->data)
        root->right = Insert(root->right, key);

    return root;
}

Node* findMin(Node* root) {
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}

Node* Delete(Node* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->data)
        root->left = Delete(root->left, key);
    else if (key > root->data)
        root->right = Delete(root->right, key);
    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        } else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

void Level_order(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            Node* curr = q.front();
            q.pop();
            cout << curr->data << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout << endl;
    }
}

int main() {
    Node* root = nullptr;

    root = Insert(root, 10);
    root = Insert(root, 5);
    root = Insert(root, 20);
    root = Insert(root, 4);
    root = Insert(root, 7);
    root = Insert(root, 15);
    root = Insert(root, 30);

    cout << "Level-wise display of BST:" << endl;
    Level_order(root);

    root = Delete(root, 20);
    cout << "\nAfter deleting 20:" << endl;
    Level_order(root);

    root = Insert(root, 25);
    cout << "\nAfter inserting 25:" << endl;
    Level_order(root);

    return 0;
}

