#include <bits/stdc++.h>

using namespace std;

int parent(int i) {
    return i >> 1;
}

int left(int i) {
    return i << 1;
}

int right(int i) {
    return (i << 1) + 1;
}


void maxHeapify(vector<int> &arr, int i) {
    int largest;
    int l = left(i);
    int r = right(i);
    if(l < arr.size() && arr[l] > arr[i]) {
        largest = l;
    }
    else {
        largest = i;
    }
    if(r < arr.size() && arr[r] > arr[largest]) {
        largest = r;
    }
    if(largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, largest);
    }
}

void buildMaxHeap(vector<int>& arr) {
    for(int i = arr.size() / 2; i >= 1; --i)
        maxHeapify(arr, i);
}

int main() {
    vector<int> heap = {-1, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    buildMaxHeap(heap);
    for(int x: heap) {
        cout << x << " ";
    }
    return 0;
}