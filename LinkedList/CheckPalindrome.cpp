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

void checkPalindromeUsingStack(node *head) {
    // pushing all nodes into stack
    node *curr = head;
    stack<node*> st;
    st.push(nullptr);
    while(curr) {
        st.push(curr);
        curr = curr -> next;
    }

    // resetting curr
    curr = head;
    while(curr && st.top() && curr != st.top()) {
        node *top = st.top();
        if(curr -> val != top -> val) {
            cout << "Not a palindrome!!!" << endl;
            return;
        }
        curr = curr -> next;
        if(curr == st.top())    break;
        st.pop();
    }
    cout << "Palindrome" << endl;
}

void checkPalindromeUsingReverse(node *head) {
    // for more info : https://leetcode.com/problems/palindrome-linked-list/discuss/1137027/JS-Python-Java-C%2B%2B-or-Easy-Floyd's-%2B-Reversal-Solution-w-Explanation

    node *slow = head, *fast = head, *prev, *temp;
    while(fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    // reversing the list
    prev = slow;
    slow = slow -> next;
    prev -> next = NULL;
    while(slow) {
        temp = slow -> next;
        slow -> next = prev;
        prev = slow;
        slow = temp;
    }

    fast = head;
    slow = prev;

    while(slow) {
        if(fast -> val != slow -> val) {
            cout << "Not a Palindrome!!!" << endl;
            return;
        }
        fast = fast -> next;
        slow = slow -> next;
    }

    cout << "Palindrome!!!" << endl;

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

    checkPalindromeUsingStack(head);

    checkPalindromeUsingReverse(head);

}