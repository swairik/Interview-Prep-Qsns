#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cout << "Enter num of elements (n>=2): ";
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int mx1 = a[0], mx2 = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(a[i] >= mx1) {
            mx2 = mx1;
            mx1 = a[i];
        }
    }
    cout << "max = " << mx1 << " " << "max2 = " << mx2 << endl;
}