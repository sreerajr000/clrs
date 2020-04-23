#include <bits/stdc++.h>

using namespace std;

void insertionSort(vector<float>& arr) {
    for(int j = 1; j < arr.size(); ++j) {
        float key = arr[j];
        int i = j - 1;
        while(i >= 0 && arr[i] > key) {
            arr[i + 1] = arr[i];
            --i;
        }
        arr[i + 1] = key;
    }
}

vector<float> bucketSort(vector<float>& arr) {
    int n = arr.size();
    vector<vector<float>> B(n);
    for(int i = 0; i < n; ++i) {
        B[floor(n * arr[i])].push_back(arr[i]);
    }
    for(int i = 0; i < n; ++i) {
        insertionSort(B[i]);
    }
    vector<float> res;
    res.reserve(n);
    for(auto x: B) {
        res.insert(res.end(), x.begin(), x.end());
    }
    return res;
}

int main() {
    vector<float> arr = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    arr = bucketSort(arr);
    for(float x: arr) {
        cout << x << " ";
    }
    return 0;
}