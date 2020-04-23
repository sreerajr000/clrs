#include <bits/stdc++.h>

using namespace std;

int minimum(vector<int> &arr) {
    int min = arr[0];
    for(int i = 1; i < arr.size(); ++i) {
        if(min > arr[i])
            min = arr[i];
    }
    return min;
}

int main() {
    vector<int> arr = {2, 4, 1, 5, 7, 6, 9, -8};
    cout << minimum(arr) << endl;
    return 0;
}