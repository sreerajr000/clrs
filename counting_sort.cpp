#include <bits/stdc++.h>

using namespace std;

vector<int> countingSort(vector<int>& arr, int k) {
    vector<int> B(arr.size());
    vector<int> C(k + 1, 0);
    for(int j = 0; j < arr.size(); ++j) {
        C[arr[j]] = C[arr[j]] + 1;
    }
    for(int i = 1; i <= k; ++i) {
        C[i] += C[i - 1];
    }
    for(int j = arr.size() - 1; j >= 0; --j) {
        B[C[arr[j]] - 1] = arr[j];
        --C[arr[j]];
    }
    return B;
}

int main() {
    vector<int> arr = {2, 5, 3, 0, 2, 3, 0, 3};
    vector<int> B = countingSort(arr, 5);
    for(int x: B) {
        cout << x << " ";
    }
    return 0;
}