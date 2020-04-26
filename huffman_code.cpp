#include <bits/stdc++.h>

using namespace std;


struct Node {
    Node* left;
    Node* right;
    char val;
    int freq;

};

Node* huffman(vector<Node*>& C) {
    int n = C.size();
    auto comp = [](Node* a, Node* b){
        return a->freq > b->freq;
    };
    priority_queue<Node*, vector<Node*>, decltype(comp)> Q(C.begin(), C.end(), comp);

    for(int i = 1; i <= n - 1; ++i) {
        Node *z = new Node();
        Node *x, *y;
        z->left = x = Q.top();
        Q.pop();
        z->right = y = Q.top();
        z->freq = x->freq + y->freq;
        Q.pop();
        Q.push(z);
    }

    Node *tmp = Q.top();
    Q.pop();
    return tmp;
}

void printCodes(Node* root, vector<int>&arr, int top = 0) {
    if(root->left != nullptr) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if(root->right != nullptr) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    
    if(root->left == nullptr && root->right == nullptr) {
        cout << root->val << " : ";
        for(int i = 0; i < top; ++i)
            cout << arr[i];
        cout << endl;
    }
}

int main() {
    vector<Node*> arr;
    vector<int> freq = {45, 13, 12, 16, 9, 5};
    char ch = 'a';
    for(auto x : freq) {
        Node* temp = new Node();
        temp->freq = x;
        temp->val = ch++;;
        arr.push_back(temp);
    }
    Node *root = huffman(arr);
    printCodes(root, freq);
    return 0;
}