#include <bits/stdc++.h>

using namespace std;

void countingSort(vector<int>& arr,int exp) { 
    int n = arr.size();
    vector<int> B(n);
    vector<int> C(10, 0);
  
    for(int i = 0; i < n; ++i){ 
        C[(arr[i] / exp) % 10]++;
    } 

    for (int i = 1; i < 10; ++i){ 
        C[i] += C[i - 1]; 
    }
  
    for (int i = n - 1; i >= 0; --i) { 
        B[C[(arr[i] / exp) % 10] - 1] = arr[i]; 
        C[(arr[i] / exp) % 10]--; 
    } 
  
    for (int i = 0; i < n; i++) 
        arr[i] = B[i]; 
} 
  

void radixSort(vector<int>& arr) { 
    int m = *max_element(arr.begin(), arr.end()); 
  
    for (int exp = 1; m/exp > 0; exp *= 10) 
        countingSort(arr, exp); 
} 

int main() {
    vector<int> arr = {329, 457, 657, 839, 436, 720, 355};
    radixSort(arr);
    for(int x: arr) {
        cout << x << " ";
    }
    return 0;
}