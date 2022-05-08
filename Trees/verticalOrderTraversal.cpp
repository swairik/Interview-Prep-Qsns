#include <bits/stdc++.h>

using namespace std;

struct node {
    int val;
    node *left;
    node * right;

    node() {
        val = 0;
        left = NULL;
        right = NULL;
    }

    node(int v) {
        val = v;
        left = NULL;
        right = NULL;
    }
};

map<int, vector<node*>> mp;

void fn(node *node, int pos) {
    if(!node) {
        return;
    }
    mp[pos].push_back(node);
    // when we go left it will pos - 1
    fn(node -> left, pos - 1);
    // when we go right it will pos + 1
    fn(node -> right, pos + 1);
}

void verticalOrderTraversal(node *root) {
    fn(root, 0);
    for(auto itr = mp.begin(); itr != mp.end(); itr++) {
        auto y = itr->second;
        for(auto node : y) {
            cout << node -> val << " ";
        }
        cout << endl;
    }
}

int main() {
    // tree taken from gfg
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->left->right = new node(8);
    root->right->right->right = new node(9);

    verticalOrderTraversal(root);

}