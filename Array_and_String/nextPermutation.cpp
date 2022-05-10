#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // curr = 1 2 3 8 7 4
    // next = 1 2 4 3 7 8
    
    // curr = 1 2 3 8  7 6
    // next = 1 2 6 3 7 8

    int i = n - 2;
    while(i >= 0 && a[i + 1] <= a[i]) {
        i--;
    }
    if(i >= 0) {
        int j = n - 1;
        while(a[j] <= a[i]) {
            j--;
        }
        swap(a[i], a[j]);
    }
    reverse(a.begin() + i + 1, a.end());

    for(auto x : a) {
        cout << x << " ";
    }
    cout << endl;

}