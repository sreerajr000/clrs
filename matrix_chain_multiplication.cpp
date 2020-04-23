#include <bits/stdc++.h>

using namespace std;

using matrix = vector<vector<int >>; 

matrix matrixMultiply(matrix& A, matrix& B) {
    if(A[0].size() != B.size()) {
        cerr << "Incompatible dimensions";
    }
    else {
        matrix C(A.size(), vector<int>(B[0].size()));
        for(int i = 0; i < A.size(); ++i) {
            for(int j = 0; j < B[0].size(); ++j) {
                C[i][j] = 0;
                for(int k = 0; k < A[0].size(); ++k) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return C;
    }
}

pair<matrix, matrix> matrixChainOrder(vector<int>& p) {
    int n = p.size() - 1;
    matrix m(n + 1, vector<int>(n + 1));
    matrix s(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; ++i) {
        m[i][i] = 0;
    }
    for(int l = 2; l <= n; ++l) {
        for(int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for(int k = i; k <= j - 1; ++k) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if(q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    return pair(m, s);
}

void printOptimalParens(matrix &s, int i, int j) {
    if(i == j) {
        cout << "A" << i;
    }
    else {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int recursiveMatrixChain(vector<int>& p, matrix& m, int i, int j) {
    if(i == j) {
        return 0;
    }
    m[i][j] = INT_MAX;
    for(int k = i; k <= j - 1; ++k) {
        int q = recursiveMatrixChain(p, m, i, k) + recursiveMatrixChain(p, m, k + 1, j) + p[i - 1] * p[k] * p[j];
        if(q < m[i][j]) {
            m[i][j] = q;
        }
    }
    return m[i][j];
}

int lookupChain(vector<int>&p, matrix& m, int i, int j) {
    if(m[i][j] < INT_MAX) {
        return m[i][j];
    }
    if(i == j) {
        return 0;
    }
    else {
        for(int k = i; k <= j - 1; ++k) {
            int q = lookupChain(p, m, i, k) + lookupChain(p, m, k + 1, j) + p[i - 1] * p[k] * p[j];
            if(q < m[i][j]) {
                m[i][j] = q;
            }
        }
    }
    return m[i][j];
}

int memoizedMatrixChain(vector<int>& p) {
    int n = p.size() - 1;
    matrix m(n + 1, vector<int>(n + 1, INT_MAX));
    return lookupChain(p, m, 1, n);
}

int main() {
    matrix A = {
        {1, 2},
        {3, 4},
        {5, 6}
    };
    matrix B = {
        {1, 2, 3},
        {4, 5, 6},
    };
    matrix C = matrixMultiply(A, B);
    for(auto row: C) {
        for(auto val: row) {
            cout << val << " ";
        }
        cout << endl;
    }

    vector<int> p = {30, 35, 15, 5, 10, 20, 25};
    auto [m, s] = matrixChainOrder(p);
    cout << m[2][5] << endl;
    printOptimalParens(s, 1, 6);
    cout << endl;

    matrix _m(p.size(), vector<int>(p.size()));
    recursiveMatrixChain(p, _m, 1, 6);
    cout << _m[2][5] << endl;

    cout << memoizedMatrixChain(p) << endl;
    return 0;
}