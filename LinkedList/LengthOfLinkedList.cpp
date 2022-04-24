#include <bits/stdc++.h>

using namespace std;

struct node {
    int val;
    node *next;

    node() {
        val = 0;
        next = nullptr;
    }
};

int main() {
    int n;
    cout << "enter the num of nodes : ";
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

    head = head -> next;
    curr = head;

    cout << "The list is : ";
    while(curr) {
        cout << curr -> val << " ";
        curr = curr -> next;
    }
    cout << endl;

    curr = head;
    int sz = 0;
    while(curr) {
        sz++;
        curr = curr -> next;
    }
    cout << "The number of elements in the list is : " << sz << endl;
    
}