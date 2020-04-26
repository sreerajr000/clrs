#include <bits/stdc++.h>

using namespace std;

set<int> recursiveActivitySelector(vector<int>& s, vector<int>& f, int k, int n) {
    int m = k + 1;
    while(m <= n && s[m] < f[k]) {
        ++m;
    }
    if(m <= n) {
        auto S = recursiveActivitySelector(s, f, m, n);
        S.insert(m);
        return S;
    }
    else {
        return {};
    }
}

set<int> greedyActivitySelector(vector<int>& s, vector<int>& f) {
    int n = s.size();
    set<int> A = {1};
    int k = 1;
    for(int m = 2; m <= n; ++m) {
        if(s[m] >= f[k]) {
            A.insert(m);
            k = m;
        }
    }
    return A;
}

int main() {
    vector<int> s = {0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    vector<int> f = {0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
    auto res = recursiveActivitySelector(s, f, 0, s.size());
    for(auto x: res) {
        cout << x << " ";
    }
    cout << endl;
    res = greedyActivitySelector(s, f);
    for(auto x: res) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}