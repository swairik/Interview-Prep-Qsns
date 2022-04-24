#include <bits/stdc++.h>

using namespace std;

int fn1(vector<int> a, vector<int> b) {
    // Space : O(n)     / Time : O(n + m)   (set creation takes O(nlogn) time)
    set<int> st(a.begin(), a.end());

    int ans = 0;
    for(auto x : b) {
        if(st.find(x) != st.end()) {
            ans++;
            st.erase(x);
        }
    }
    return ans;
}

int fn2(vector<int> a, vector<int> b) {
    // Space : O(1)     / Time : O(nlogn + mlogm + n + m);
    
    int n = (int)a.size(), m = (int)b.size();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0;
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(a[i] == b[j]) {
            ans++;
        }
        if(a[i] < b[j]) i++;
        else if(a[i] > b[j])   j++;
        else    i++, j++;

        while(i < n && a[i] == a[max(0, i - 1)])    i++;
        while(j < m && b[j] == b[max(0, j - 1)])    j++;
    }
    return ans;
}

int main() {
    int n;
    cout << "enter the num of elems of array 1 : ";
    cin >> n;
    vector<int> a(n);
    cout << "enter elems : ";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m;
    cout << "enter the num of elems of array 2 : ";
    cin >> m;
    vector<int> b(m);
    cout << "enter elems : ";
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    cout << fn1(a, b) << endl;
    cout << fn2(a, b) << endl;

}