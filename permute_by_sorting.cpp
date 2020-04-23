#include <bits/stdc++.h>

using namespace std;

void permuteBySorting(vector<int>& arr) {
    int n = arr.size();
    vector<pair<int, int> > P(n);
    for(int i = 0; i < n; ++i) {
        int temp = rand() % (n * n * n);
        P[i] = pair(temp, arr[i]);
    }
    sort(P.begin(), P.end());
    for(int i = 0; i < n; ++i) {
        arr[i] = P[i].second;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    permuteBySorting(arr);
    for(int x: arr) {
        cout << x << " ";
    }
    return 0;
}