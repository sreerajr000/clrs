#include <bits/stdc++.h>

using namespace std;

void insertionSort(vector<int>& arr) {
    for(int j = 1; j < arr.size(); ++j) {
        int key = arr[j];
        int i = j - 1;
        while(i >= 0 && arr[i] > key) {
            arr[i + 1] = arr[i];
            --i;
        }
        arr[i + 1] = key;
    }
}


int main() { 
    vector<int> arr = {5, 6, 3, 23, 1};
    insertionSort(arr);
    for(int x: arr) {
        cout << x << " ";
    }
    return 0;
}