#include <bits/stdc++.h>

using namespace std;

int cutRod(vector<int>& p, int n) {
    if(n == 0) {
        return 0;
    }
    int q = INT_MIN;
    for(int i = 0; i < n; ++i) {
        q = max(q, p[i] + cutRod(p, n - i - 1));
    }
    return q;
}

int memoizedCutRodAux(vector<int>& p, int n, vector<int>& r) {
    if(r[n] >= 0) {
        return r[n];
    }
    int q;
    if(n == 0) {
        q = 0;
    }
    else {
        q = INT_MIN;
        for(int i = 0; i < n; ++i) {
            q = max(q, p[i] + memoizedCutRodAux(p, n - i - 1, r));
        }
    }
    r[n] = q;
    return q;
}

int memoizedCutRod(vector<int>& p, int n) {
    vector<int> r(n + 1, INT_MIN);
    return memoizedCutRodAux(p, n, r);
}

int bottomUpCutRod(vector<int>& p, int n) {
    vector<int> r(n + 1);
    r[0] = 0;
    for(int j = 1; j <= n; ++j) {
        int q = INT_MIN;
        for(int i = 0; i < j; ++i) {
            q = max(q, p[i] + r[j - i - 1]);
        }
        r[j] = q;
    }
    return r[n];
}

tuple<vector<int>, vector<int>> extendedBottomUpCutRod(vector<int>& p, int n) {
    vector<int> r(n + 1), s(n + 1);
    r[0] = 0;
    for(int j = 1; j <= n; ++j) {
        int q = INT_MIN;
        for(int i = 0; i < j; ++i) {
            if(q < p[i] + r[j - i - 1]) {
                q = p[i] + r[j - i - 1];
                s[j] = i;
            }
        }
        r[j] = q;
    }
    return tuple(r, s);
}

void printCutRodSolutions(vector<int>& p, int n) {
    auto [r, s] = extendedBottomUpCutRod(p, n);
    while(n > 0) {
        cout << s[n] +  1 << " ";
        n = n - s[n] - 1;
    }
}

int main() {
    vector<int> p = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    cout << cutRod(p, 4) << endl;
    cout << memoizedCutRod(p, 4) << endl;
    cout << bottomUpCutRod(p, 4) << endl;
    printCutRodSolutions(p, 7);
    return 0;
}