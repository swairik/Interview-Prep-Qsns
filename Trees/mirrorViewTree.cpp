#include <bits/stdc++.h>

using namespace std;

struct node {
    int val;
    node *left, *right;

    node() {
        val = 0;
        left = nullptr;
        right = nullptr;
    }

    node(int v) {
        val = v;
        left = nullptr;
        right = nullptr;
    }

};

void mirrorView(node *root) {
    if(!root) {
        return;
    }
    mirrorView(root -> left);
    mirrorView(root -> right);
    node *temp = root -> left;
    root -> left = root -> right;
    root -> right = temp;
}

// inorder traversal
void traverse(node *root) {
    if(!root) {
        return;
    }
    traverse(root -> left);
    cout << root -> val << " ";
    traverse(root -> right);
}

int main() {
    // tree built from gfg
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    cout << "BEFORE : ";
    traverse(root);
    cout << endl;

    mirrorView(root);

    cout << "AFTER : ";
    traverse(root);
    cout << endl;

}