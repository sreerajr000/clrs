#include <bits/stdc++.h>

using namespace std;

void bubbleSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        for (int j = arr.size() - 1; j >= i + 1; --j)
        {
            if (arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1]);
        }
    }
}

int main()
{
    vector<int> arr = {1, 6, 3, 7, 10, 2, 4, 8};
    bubbleSort(arr);
    for (int x : arr)
        cout << x << " ";
    return 0;
}