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
    stack<node*> st;
    node *curr = root;

    // while(curr || !st.empty()) {
    //     while(curr) {
    //         cout << curr -> val << " ";

    //         if(curr -> right) {
    //             st.push(curr -> right);
    //         }

    //         curr = curr -> left;
    //     }

    //     if(!st.empty()) {
    //         curr = st.top();
    //         st.pop();
    //     }
    // }

    st.push(curr);
    while(!st.empty()) {
        curr = st.top();
        st.pop();
        
        cout << curr -> val << " ";

        if(curr -> right) {
            st.push(curr -> right);
        }
        if(curr -> left) {
            st.push(curr -> left);
        }
    }
}

void inorder(node *root) {
    stack<node*> st;
    node *curr = root;

    while(curr || !st.empty()) {
        while(curr) {
            st.push(curr);
            curr = curr -> left;
        }
        curr = st.top();
        st.pop();

        cout << curr -> val << " ";

        curr = curr -> right;
    }

}

void postorder(node *root) {
    stack<node*> st;
    stack<node*> ans;

    node *curr = root;
    st.push(curr);
    while(!st.empty()) {
        curr = st.top();
        st.pop();
        
        ans.push(curr);

        if(curr -> left) {
            st.push(curr -> left);
        }
        if(curr -> right) {
            st.push(curr -> right);
        }
    }
    while(!ans.empty()) {
        cout << ans.top() -> val << " ";
        ans.pop();
    }

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