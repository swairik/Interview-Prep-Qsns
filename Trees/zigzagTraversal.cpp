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

void zigzag(node *root) {
    queue<node*> q;
    q.push(root);
    int level = 0;
    while(!q.empty()) {
        int sz = (int)q.size();
        vector<int> temp;
        for(int i = 0; i < sz; i++) {
            auto node = q.front();
            q.pop();
            temp.push_back(node -> val);
            if(node -> left)    q.push(node -> left);
            if(node -> right)    q.push(node -> right);
        }
        if(level & 1) {
            reverse(temp.begin(), temp.end());
        }
        for(auto x : temp) {
            cout << x << " ";
        }
        cout << endl;

        level++;
    }
}

int main() {
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->left->right = new node(8);
    root->right->right->right = new node(9);

    zigzag(root);
    
}