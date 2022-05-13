#include <bits/stdc++.h>

using namespace std;

struct node {
    int val;
    node *left, *right;

    node(int v) {
        val = v;
        left = nullptr;
        right = nullptr;
    }
};

node* insert(node *root, int v) {
    // Doesn't deal with equal values
    if(!root) {
        return new node(v);
    }
    if(root -> val < v) {
        root -> right = insert(root -> right, v);
    }
    else {
        root -> left = insert(root -> left, v);
    }
    return root;
}

node *search(node *root, int v) {
    if(!root || root -> val == v) {
        return root;
    }
    if(root -> val < v) 
        return search(root -> right, v);
    return search(root -> left, v);
}

void print(node *root) {
    if(!root)   return;
    print(root -> left);
    cout << root -> val << " ";
    print(root -> right);
}

int main() {
    // Insertion
    node *root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    print(root);
    cout << endl;

    // Searching
    if(search(root, 80)) {
        cout << "Found 80" << endl;
    }
    else {
        cout << "NOT FOUND 80" << endl;
    }

    if(search(root, 100)) {
        cout << "Found 100" << endl;
    }
    else {
        cout << "NOT FOUND 100" << endl;
    }

    


}