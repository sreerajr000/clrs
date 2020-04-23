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

void quickSort(vector<int> & arr, int p, int r) {
    if(p < r) {
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}

int main() {
    vector<int> arr = {2, 8, 7, 1, 3, 5, 6, 4};
    quickSort(arr, 0, arr.size() - 1);
    // partition(arr, 0, arr.size() - 1);
    for(int x: arr) {
        cout << x << " ";
    }
    return 0;
}