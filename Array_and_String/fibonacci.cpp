#include <bits/stdc++.h>

using namespace std;

int recursiveFib(int n) {
    if(n <= 1) {
        return n;
    }
    return recursiveFib(n - 1) + recursiveFib(n - 2);
} 

int iterativeFib(int n) {
    if(n <= 1)  return n;
    vector<int> dp(n + 1);
    dp[0] = 0, dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int spaceOptimisedFib(int n) {
    if(n <= 1)  return n;
    int a = 0, b = 1;
    for(int i = 2; i <= n; i++) {
        b = a + b;
        a = b - a;
    }
    return b;
}


int constantFib(int n) {
    const double root5 = sqrt(5);
    const double val = (1 + root5) / 2;
    return round(pow(val, n) / (root5));
}

struct Matrix {
    int a[2][2];

    // Matrix() {
    //     a[0][0] = 1;    a[0][1] = 1;
    //     a[1][0] = 1;    a[1][1] = 0;
    // }

    Matrix operator * (Matrix other) {
        Matrix product{{{0, 0}, {0, 0}}};
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                for(int k = 0; k < 2; k++) {
                    product.a[i][k] += a[i][j] * other.a[j][k];
                }
            }
        }
        return product;
    }
};

Matrix fn(Matrix temp, Matrix mat, int n) {
    n += 1;
    while(n) {
        if(n & 1) {
            temp = temp * mat;
        }
        mat = mat * mat;
        n >>= 1;
    }
    return temp;
}

int lognFib(int n) {
    Matrix mat{{{0, 1}, {1, 1}}};
    Matrix temp{{{1, 0}, {0, 1}}};
    temp = fn(temp, mat, n);
    // for(int i = 0; i <= n; i++) {
    //     temp = temp * mat;
    // }
    return temp.a[0][0];
}

int main() {
    int n;
    cin >> n;
    cout << "recursive = " << recursiveFib(n) << endl;
    cout << "iterative = " << iterativeFib(n) << endl;
    cout << "space optmised = " << spaceOptimisedFib(n) << endl;
    cout << "constant = " << constantFib(n) << endl;
    cout << "Log n time = " << lognFib(n);
}