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

node *getMiddle1(node *head) {
    // if odd num of nodes returns the middle element
    // if even num of nodes returns the FIRST middle element        -->> not same as getMiddle2() function
    
    node *slow = nullptr, *fast = head;
    while(fast && fast -> next) {
        slow = slow == nullptr ? head : slow -> next;
        fast = fast -> next -> next;
    }

    if(fast) {
        slow = slow == nullptr ? head : slow -> next;
    }

}

node *getMiddle2(node *head) {
    // if odd num of nodes returns the middle element
    // if even num of nodes returns the SECOND middle element       -->> not same as getMiddle1() function
    
    node *slow = head, *fast = head;
    while(fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
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

    // removing the dummy head
    head = head -> next;

    cout << "The list is : ";
    print(head);

    node *mid = getMiddle2(head);
    cout << "the middle element is : " << mid -> val << endl;


    cout << "The first mid is : " << getMiddle1(head) -> val;
}