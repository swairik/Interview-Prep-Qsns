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

void loopUsingWhile(node *head) {
    node *slow = head, *fast = head;

    bool loopPresent = false;
    while(fast && fast -> next) {
        fast = fast -> next -> next;
        slow = slow -> next;

        if(fast == slow) {
            loopPresent = true;
            break;
        }
    }
    
    if(!loopPresent) {
        cout << "there is no loop in this list" << endl;
        return;
    }

    // finding the loop beginning point
    slow = head;
    while(slow != fast) {
        slow = slow -> next;
        fast = fast -> next;
    }

    cout << "The loop begins at " << slow -> val << endl;
}

void loopUsingDoWhile(node *head) {
    node *slow = head, *fast = head;

    do {
        if(!fast -> next || !fast -> next -> next) {
            cout << "There is no loop in the list" << endl;
            return;
        }
        slow = slow -> next;
        fast = fast -> next -> next;
    } while(slow != fast);
    
    cout << "There is a loop in this list" << endl;

    // finding the loop beginning point
    slow = head;
    while(slow != fast) {
        slow = slow -> next;
        fast = fast -> next;
    }

    cout << "The loop begins at " << slow -> val << endl;
}

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

    // comment/uncomment below lines for testing
    // if(curr != head -> next)             // making a linked list with a loop by setting next ptr of last node equal to some node
    //     curr -> next = head -> next -> next;

    head = head -> next;

    loopUsingDoWhile(head);
    loopUsingDoWhile(head);

}