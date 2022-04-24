#include <bits/stdc++.h>

using namespace std;

struct node {
    int val;
    node *next;

    node() {
        val = 0;
        next = NULL;
    }

};

int main() {
    // number of nodes
    int n;
    cin >> n;

    node *head = new node();
    node *curr = head;

    for(int i = 0; i < n; i++) {
        int v;
        cin >> v;
        node *temp = new node();
        temp -> val = v; 
        curr -> next = temp;
        curr = curr -> next;
    }
    
    node *temp = head -> next;
    cout << "the linked list is : ";
    while(temp) {
        cout << temp -> val << " ";
        temp = temp -> next;
    }
    cout << endl;

    // reversing the list
    node *before = NULL,  *after;
    curr = head -> next;

    while(curr) {
        after = curr -> next;
        curr -> next = before;
        before = curr;
        curr = after;
    }

    node *newHead = before;
    temp = newHead;

    cout << "after reversing the list : ";
    while(temp) {
        cout << temp -> val << " ";
        temp = temp -> next;
    }
    cout << endl;

}