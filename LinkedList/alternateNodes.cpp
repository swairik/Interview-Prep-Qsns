#include <bits/stdc++.h>

using namespace std;

struct node {
    int val;
    node *next;

    node(int v) {
        val = v;
        next = nullptr;
    }

    node() {
        val = 0;
        next = nullptr;
    }
};

int main() {
    int n;
    cin >> n;
    node *head = new node();
    node *curr = head;
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        node *temp = new node(val);
        curr -> next = temp;
        curr = curr -> next;
    }
    head = head -> next;
    curr = head;

    bool print = true;
    
    while(curr) {
        if(print) {
            cout << curr -> val << " ";
        }
        print = !print;
        curr = curr -> next;
    }
    
}