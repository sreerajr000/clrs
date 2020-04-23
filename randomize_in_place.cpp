#include <bits/stdc++.h>

using namespace std;

void randomizeInPlace(vector<int> &arr) {
    int n = arr.size();
    for(int i = 0; i < n; ++i) {
        int temp = rand() % (n - i) + i;
        swap(arr[i], arr[temp]);
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    randomizeInPlace(arr);
    for(int x: arr)
        cout << x << " ";
    return 0;
}