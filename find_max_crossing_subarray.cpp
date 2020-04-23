#include <bits/stdc++.h>

using namespace std;

tuple<int, int, int> findMaxCrossingSubarray(vector<int>& arr, int low, int mid, int high) {
    int left_sum = INT_MIN;
    int sum = 0;
    int max_left, max_right;
    for(int i = mid; i >= low; --i) {
        sum += arr[i];
        if(sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }
    int right_sum = INT_MIN;
    sum = 0;
    for(int j = mid + 1; j <= high; ++j) {
        sum += arr[j];
        if(sum > right_sum) {
            right_sum = sum;
            max_right = j;
        }
    }

    return tuple(max_left, max_right, left_sum + right_sum);
}

int main() {
    vector<int> arr = {-16, -23, 18, 20, -7, 12, -5, 10};
    auto [max_left, max_right, sum] = findMaxCrossingSubarray(arr, 0, arr.size()/2 - 1, arr.size() - 1);
    cout << max_left << " " <<  max_right << " " << sum << endl;
    return 0;
}