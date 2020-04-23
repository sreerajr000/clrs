#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &arr, int p, int r) {
    int x = arr[r];
    int i = p - 1;
    for(int j = p; j <= r - 1; ++j) {
        if(arr[j] <= x) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

int randomizedPartition(vector<int>& arr, int p, int r) {
    int i = rand() % (r - p + 1) + p;
    swap(arr[i], arr[r]);
    return partition(arr, p, r);
}


int randomizedSelect(vector<int> &arr, int p, int r, int i) {
    if(p == r) {
        return arr[p];
    }
    int q = randomizedPartition(arr, p, r);
    int k = q - p + 1;
    if (i == k) {
        return arr[q];
    }
    else if(i < k) {
        return randomizedSelect(arr, p, q - 1, i);
    }
    else {
        return randomizedSelect(arr, q + 1, r, i - k);
    }
}

int main() {
    vector<int> arr = {4, 2, 5, 7, 8, 1, 3, 0};
    cout << randomizedSelect(arr, 0, arr.size() - 1, 5) << endl;
    return 0;
}