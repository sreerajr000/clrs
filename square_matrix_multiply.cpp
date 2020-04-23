#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> squareMatrixMultiply(vector<vector<int>> &A, vector<vector<int>> &B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            C[i][j] = 0;
            for(int k = 0; k < n; ++k) {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

int main() {
    vector<vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<vector<int>> B = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    vector<vector<int>> C = squareMatrixMultiply(A, B);
    for(auto row: C) {
        for(auto val: row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}