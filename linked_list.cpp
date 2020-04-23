#include<bits/stdc++.h>

using namespace std;

struct Node {
    int key;
    Node* next;
    Node* prev;

    Node(int x): key(x), next(nullptr), prev(nullptr) {}
};

struct List {
    Node* head = nullptr;
};

Node* listSearch(List& L, int k) {
    Node* x = L.head;
    while(x != nullptr && x->key != k) {
        x = x->next;
    }
    return x;
}

void listInsert(List& L, Node* x) {
    x->next = L.head;
    if(L.head != nullptr) {
        L.head->prev = x;
    }
    L.head = x;
    x->prev = nullptr;
}

void listDelete(List& L, Node *x) {
    if(x->prev != nullptr) {
        x->prev->next = x->next;
    }
    else {
        L.head = x->next;
    }
    if(x->next != nullptr) {
        x->next->prev = x->prev;
    }
}

void print(List& l) {
    Node* head = l.head;
    while(head!= nullptr) {
        cout << head->key << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    List l;
    listInsert(l, new Node(3));
    listInsert(l, new Node(4));
    listInsert(l, new Node(1));
    listInsert(l, new Node(5));
    print(l);
    Node *tmp = listSearch(l, 3);
    if(tmp == nullptr) {
        cout << "Not found\n";
    }
    else {
        cout << tmp->key << endl;
    }
    listDelete(l, tmp);
    print(l);    
    return 0;
}