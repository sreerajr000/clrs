#include <bits/stdc++.h>

using namespace std;

using matrix = vector<vector<int>>;

enum {TOP_LEFT, TOP, EMPTY};

pair<matrix, matrix> lcsLength(vector<int>& X, vector<int>& Y) {
    int m = X.size();
    int n = Y.size();
    matrix b(m + 1, vector<int>(n + 1));
    matrix c(m + 1, vector<int>(n + 1));
    for(int i = 1; i <= m; ++i) {
        c[i][0] = 0;
    }
    for(int j = 0; j <= n; ++j) {
        c[0][j] = 0;
    }
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(X[i] == Y[j]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = TOP_LEFT;
            }
            else if(c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = TOP;
            }
            else {
                c[i][j] = c[i][j - 1];
                b[i][j] = EMPTY;
            }
        }
    }
    return pair(c, b);
}

void printLCS(matrix &b, vector<int>& X, int i, int j) {
    if(i == 0 || j == 0) {
        return;
    }
    if(b[i][j] == TOP_LEFT) {
        printLCS(b, X, i - 1, j - 1);
        cout << X[i] << " ";
    }
    else if(b[i][j] == TOP) {
        printLCS(b, X, i - 1, j);
    }
    else {
        printLCS(b, X, i, j - 1);
    }
}

int main() {
    return 0;
}