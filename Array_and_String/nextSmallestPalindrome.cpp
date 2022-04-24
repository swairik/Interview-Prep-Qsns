#include <bits/stdc++.h>

using namespace std;

string inc(string s) {
    string ans = "";
    
    reverse(s.begin(), s.end());
    bool carry = true;

    for(int i = 0; i < (int)s.size(); i++) {
        if(carry) {
            int val = s[i] - '0';
            val++;
            if(val > 10) {
                ans = '0' + ans;
            }
            else {
                ans = to_string(val) + ans;
                carry = false;
            }
        }
        else {
            ans = s[i] + ans;
        }
    }
    return ans;

}

string nextSmallestPalindrome(string s) {
    int n = (int)s.size();

    // edge case if the string contains all 9's
    if(count(s.begin(), s.end(), '9') == n) {
        string ans = "1";
        for(int i = 0; i < n - 1; i++) {
            ans += '0';
        }
        ans += '1';
        return ans;
    }

    if(n & 1) {
        // odd length strings
        string firstHalf = s.substr(0, n / 2 + 1);

        string reversedFirstHalf = s.substr(0, n / 2);
        reverse(reversedFirstHalf.begin(), reversedFirstHalf.end());

        if(s < firstHalf + reversedFirstHalf) {
            return firstHalf + reversedFirstHalf;
        }

        firstHalf = inc(firstHalf);
        string ans = firstHalf;

        reversedFirstHalf = firstHalf.substr(0, n / 2);
        reverse(reversedFirstHalf.begin(), reversedFirstHalf.end());

        return firstHalf + reversedFirstHalf;

    }   
    else {
        // even length strings
        string firstHalf = s.substr(0, n / 2);
        
        string reversedFirstHalf = firstHalf;
        reverse(reversedFirstHalf.begin(), reversedFirstHalf.end());

        if(firstHalf + reversedFirstHalf > s) {
            return firstHalf + reversedFirstHalf;
        }

        firstHalf = inc(firstHalf);

        reversedFirstHalf = firstHalf;
        reverse(reversedFirstHalf.begin(), reversedFirstHalf.end());

        return firstHalf + reversedFirstHalf;

    }
}

int main() {
    // using string bcz it is more simple

    string s;
    cout << "enter a number : ";
    cin >> s;

    cout << nextSmallestPalindrome(s);
}