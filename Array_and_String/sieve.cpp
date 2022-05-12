#include <bits/stdc++.h>

using namespace std;

vector<int> getPrimes(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i <= n; i++) {
        if(!isPrime[i]) continue;
        for(int j = i * i; j <= n; j += i) {
            isPrime[j] = false;
        }
    }
    vector<int> ans;
    for(int i = 0; i <= n; i++) {
        if(isPrime[i])  ans.push_back(i);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> primes = getPrimes(n);
    for(auto x : primes)    cout << x << " ";
    cout << endl;
}