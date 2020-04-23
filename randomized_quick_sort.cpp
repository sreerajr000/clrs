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

void randomizedQuickSort(vector<int> & arr, int p, int r) {
    if(p < r) {
        int q = randomizedPartition(arr, p, r);
        randomizedQuickSort(arr, p, q - 1);
        randomizedQuickSort(arr, q + 1, r);
    }
}

int main() {
    vector<int> arr = {2, 8, 7, 1, 3, 5, 6, 4};
    randomizedQuickSort(arr, 0, arr.size() - 1);
    for(int x: arr) {
        cout << x << " ";
    }
    return 0;
}