#include <bits/stdc++.h>

using namespace std;

struct node {
    int val;
    node *left;
    node *right;

    node(int v) {
        val = v;
        left = nullptr;
        right = nullptr;
    }
};

void preorder(node *root) {
    if(!root) {
        return;
    }
    cout << root -> val << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void inorder(node *root) {
    if(!root) {
        return;
    }
    inorder(root -> left);
    cout << root -> val << " ";
    inorder(root -> right);
}

void postorder(node *root) {
    if(!root) {
        return;
    }
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> val << " ";
}

int main() {
    // tree looks like :
    //                   1
    //           2               3
    //      4        5       6       7

    node *root = new node(1);

    root -> left = new node(2);
    root -> right = new node(3);

    root -> left -> left = new node(4);
    root -> left -> right = new node(5);
    
    root -> right -> left = new node(6);
    root -> right -> right = new node(7);

    cout << "preorder : ";
    preorder(root);
    cout << endl;

    cout << "inorder : ";
    inorder(root);
    cout << endl;

    cout << "postorder : ";
    postorder(root);
    cout << endl;

}