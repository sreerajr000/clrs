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

tuple<int, int, int> findMaximumSubarray(vector<int>& arr, int low, int high) {
    if(high == low) {
        return tuple(low, high, arr[low]);
    }
    else {
        int mid = (low + high) / 2;
        auto [left_low, left_high, left_sum] = findMaximumSubarray(arr, low, mid);
        auto [right_low, right_high, right_sum] = findMaximumSubarray(arr, mid + 1, high);
        auto [cross_low, cross_high, cross_sum] = findMaxCrossingSubarray(arr, low, mid, high);
        if(left_sum >= right_sum && left_sum >= cross_sum) {
            return tuple(left_low, left_high, left_sum);
        }
        else if(right_sum >= left_sum && right_sum >= cross_sum) {
            return tuple(right_low, right_high, right_sum);
        }
        else {
            return tuple(cross_low, cross_high, cross_sum);
        }
    }
}

int main() {
    vector<int> arr = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    auto [max_left, max_right, sum] = findMaximumSubarray(arr, 0, arr.size() - 1);
    cout << max_left << " " <<  max_right << " " << sum << endl;
    return 0;
}