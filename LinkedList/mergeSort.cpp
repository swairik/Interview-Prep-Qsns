// mergeSort 2 lists using recursive merge Sort
// for more info : https://leetcode.com/problems/sort-list/solution/

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

void print(node *curr) {
    while(curr) {
        cout << curr -> val << " ";
        curr = curr -> next;
    }
    cout << endl;
}

node *merge(node *left, node *right) {
    node *dummy = new node();
    node *temp = dummy;

    while(left && right) {
        if(left -> val < right -> val) {
            temp -> next = left;
            left = left -> next;
        }
        else {
            temp -> next = right;
            right = right -> next;
        }
        temp = temp -> next;
    }

    if(left)    temp -> next = left;
    else    temp -> next = right;

    return dummy -> next;
}

node *getMiddle(node *head) {
    node *midPrev = nullptr;
    while(head && head -> next) {
        midPrev = (midPrev == nullptr) ? head : midPrev -> next;
        head = head -> next -> next;
    }
    node *mid = midPrev -> next;
    midPrev -> next = nullptr;
    return mid;
    
}

node* sort(node *head) {
    if(!head || !head -> next) {
        return head;
    }
    node *mid = getMiddle(head);
    node *left = sort(head);
    node *right = sort(mid);
    return merge(left, right);
}

int main() {
    int n;
    cout << "enter the number of nodes : ";
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

    // removes the dummy pointer
    head = head -> next;

    cout << "The list is : ";
    print(head);

    head = sort(head);

    cout << "After sorting the list is : ";
    print(head);

}