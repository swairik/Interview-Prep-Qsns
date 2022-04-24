// Count of longest possible subarrays with sum not divisible by K

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sum = accumulate(a.begin(), a.end(), 0); 
    // if entire sum is not divisible by k the ans is 1 subarray, i.e the whole subarray
    if(sum % k != 0) {
        cout << 1 << endl;
    }
    else {
        // find the max subarray size
        int ans = 0;
        int i = 0, j = n - 1;

        while(sum % k == 0 && i < n) {
            sum -= a[i++];
        }
        if(i == n) {
            cout << 0 << endl;
            return 0;
        }
        int rem1 = n - i;
        
        sum = accumulate(a.begin(), a.end(), 0);
        while(sum % k == 0 && j >= 0) {
            sum -= a[j--];
        }
        int rem2 = n - j - 1;
        
        int windowSize = max(rem1, rem2);
        sum = 0;
        
        // sliding window using the max subarray size
        
        for(int i = 0; i < windowSize - 1; i++) {
            sum += a[i];
        }
        for(int i = windowSize - 1; i < n; i++) {
            sum += a[i];
            if(i >= windowSize) {
                sum -= a[i - windowSize];
            }
            if(sum % k != 0)    ans++;
        }
        cout << ans << endl;
    }
}