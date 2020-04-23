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

void mergeSort(vector<int>& arr, int p, int r) {
    if(p < r) {
        int q = floor((p + r)/ 2);
        mergeSort(arr, p , q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}


int main() {
    vector<int> arr = {1, 4, 2, 3, 10, 5, 7, 9};
    mergeSort(arr, 0, arr.size() - 1);
    for(int x: arr)
        cout << x << " ";
    return 0;
}