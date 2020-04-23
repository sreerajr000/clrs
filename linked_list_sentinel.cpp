#include <bits/stdc++.h>

using namespace std;

struct Node {
    int key;
    Node* prev;
    Node* next;
    Node(int x): key(x), prev(nullptr), next(nullptr) {}
};


struct List {
    Node* head;
    Node* nil;

    List() {
        nil = new Node(-1);
        nil->next = nil;
        nil->prev = nil;
    }
};

void listDelete(List& L, Node* x) {
    x->prev->next = x->next;
    x->next->prev = x->prev;
}

Node* listSearch(List& L, int k) {
    Node* x = L.nil->next;
    while(x != L.nil && x->key != k) {
        x = x->next;
    }
    return x;
}

void listInsert(List& L, Node* x) {
    x->next = L.nil->next;
    L.nil->next->prev = x;
    L.nil->next = x;
    x->prev = L.nil;
}

void print(List& L) {
    Node* x = L.nil->next;
    while(x != L.nil) {
        cout << x->key << " ";
        x = x->next;
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