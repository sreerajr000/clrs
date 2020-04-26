#include <bits/stdc++.h>

using namespace std;

using matrix_i = vector<vector<int>>;
using matrix_f = vector<vector<float>>;

pair<matrix_f, matrix_i> optimalBST(vector<float>& p, vector<float>& q, int n) {
    matrix_f e(n + 2, vector<float>(n + 1));
    matrix_f w(n + 2, vector<float>(n + 1));
    matrix_i root(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n + 1; ++i) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    for(int l = 1; l <= n; ++l) {
        for(int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            e[i][j] = INT_MAX;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            for(int r = i; r <= j; ++r) {
                float t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if(t < e[i][j]) {
                    e[i][j] = t;
                    root[i][j] = r;
                }
            }
        }
    }
    return pair(e, root);
}

void printOBST(matrix_i& root, int i, int j){
    if (j < i) {
        return;
    }

    cout << "(";
    printOBST(root, i,root[i][j]-1);
    cout << root[i][j];
    printOBST(root, root[i][j]+1,j);
    cout << ")";
}

int main() {
    vector<float> p = {0.0, 0.15, 0.10, 0.05, 0.10, 0.20};
    vector<float> q = {0.05, 0.10, 0.05, 0.05, 0.05, 0.10};
    auto [e, root] = optimalBST(p, q, p.size());
    cout << e[1][5] << endl;
    printOBST(root, 1, 5);
    return 0;
}