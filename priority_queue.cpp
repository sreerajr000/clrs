#include <bits/stdc++.h>

using namespace std;

class PriorityQueue {
    private:
    vector<int> heap;
    int heapSize;

    int parent(int i) {
        return i >> 1;
    }

    int left(int i) {
        return i << 1;
    }

    int right(int i) {
        return (i << 1) + 1;
    }


    void maxHeapify(int i) {
        int largest;
        int l = left(i);
        int r = right(i);
        if(l < heapSize && heap[l] > heap[i]) {
            largest = l;
        }
        else {
            largest = i;
        }
        if(r < heapSize && heap[r] > heap[largest]) {
            largest = r;
        }
        if(largest != i) {
            swap(heap[i], heap[largest]);
            maxHeapify(largest);
        }
    }

    void buildMaxHeap() {
        for(int i = heap.size() / 2; i >= 1; --i)
            maxHeapify(i);
    }

    public:

    PriorityQueue(vector<int> arr) {
        heap = arr;
        heapSize = heap.size();
        buildMaxHeap();
    }

    int heapMaximum() {
        return heap[1];
    }

    int heapExtractMax() {
        if(heapSize <= 1){
            //throw
        }
        int max = heap[1];
        heap[1] = heap[heapSize - 1];
        --heapSize;
        maxHeapify(1);
        return max;
    }

    void heapIncreaseKey(int i, int key) {
        if(key < heap[i]) {
            //throw error
        }
        heap[i] = key;
        while(i > 1 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void maxHeapInsert(int key) {
        ++heapSize;
        heap.push_back(INT_MIN);
        heapIncreaseKey(heapSize - 1, key);
    }

    void printHeap() {
        for(int i = 1; i < heapSize; ++i) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

};



int main() {
    vector<int> heap = {-1, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7};

    PriorityQueue pq(heap);
    pq.printHeap();
    cout << pq.heapMaximum() << endl;
    cout << pq.heapExtractMax() << endl;

    pq.printHeap();
    pq.heapIncreaseKey(3, 15);
    pq.printHeap();
    pq.maxHeapInsert(50);
    pq.printHeap();

    return 0;
}