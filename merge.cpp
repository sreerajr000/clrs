#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &arr, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    vector<int> left(n1 + 1), right(n2 + 1);

    for(int i = 0; i < n1; ++i) {
        left[i] = arr[p + i];
    }
    for(int j = 0; j < n2; ++j) {
        right[j] = arr[q + j + 1];
    }
    left[n1] = INT_MAX;
    right[n2] = INT_MAX;

    int i = 0;
    int j = 0;
    for(int k = p; k <= r; ++k) {
        if(left[i] <= right[j]) {
            arr[k] = left[i];
            ++i;
        }
        else {
            arr[k] = right[j];
            ++j;
        }
    } 
}


int main() {
    vector<int> arr = {1, 3, 5, 7, 2, 4, 6, 8};
    merge(arr, 0, arr.size() / 2 - 1, arr.size() - 1);
    for(int x: arr)
        cout << x << " ";
    return 0;
}