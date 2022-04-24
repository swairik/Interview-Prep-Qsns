#include <bits/stdc++.h>

using namespace std;

struct node {
    int val;
    node *next;
    node *prev;

    node() {
        val = 0;
        next = NULL;
        prev = NULL;
    }

};

void print(node *curr) {
    while(curr) {
        cout << "node : " << curr -> val << endl;
        cout << "\t";
        if(curr -> prev) {
            cout << "prev : " << curr -> prev -> val;
        }
        else {
            cout << "prev : " << "NULL";
        }
        cout << endl;

        cout << "\t";
        if(curr -> next) {
            cout << "next : " << curr -> next -> val;
        }
        else {
            cout << "next : " << "NULL";
        }
        cout << endl;
        curr = curr -> next;
    }
}

int main() {
    int n;
    cout << "enter num of nodes : ";
    cin >> n;

    node *head = new node();
    node *curr = head;

    for(int i = 0; i < n; i++) {
        int v;
        cin >> v;
        node *temp = new node();
        temp -> val = v;
        curr -> next = temp;
        temp -> prev = curr;
        curr = curr -> next;
    }

    head = head -> next;
    head -> prev = NULL;

    cout << "list : " << endl;
    print(head);    

    node *before = head;
    curr = head;
    while(curr) {
        before = curr -> prev;
        curr -> prev = curr -> next;
        curr -> next = before;
        curr = curr -> prev;
    }

    node *newHead = !before ? curr : before -> prev;

    cout << "reversed list : " << endl;
    print(newHead);
}