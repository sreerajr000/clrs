#include <bits/stdc++.h>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node* p;
    Node(int x) : key(x), left(nullptr), right(nullptr), p(nullptr) {}
};

struct Tree {
    Node* root;
    Tree() : root(nullptr) {}
};

Node* treeSearch(Node* x, int k) {
    if(x == nullptr || k == x->key) {
        return x;
    }
    if(k < x->key) {
        return treeSearch(x->left, k);
    }
    return treeSearch(x->right, k);
}

Node* iterativeTreeSearch(Node* x, int k) {
    while(x != nullptr && k != x->key) {
        if(k < x->key) {
            x = x->left;
        }
        else {
            x = x->right;
        }
    }
    return x;
}

Node* treeMinimum(Node* x) {
    while(x->left != nullptr) {
        x = x->left;
    }
    return x;
}

Node* treeMaximum(Node* x) {
    while(x->right != nullptr) {
        x = x->right;
    }
    return x;
}

void inorderTreeWalk(Node* x) {
    if(x != nullptr) {
        inorderTreeWalk(x->left);
        cout << x->key << " ";
        inorderTreeWalk(x->right);
    }
}

Node* treeSuccessor(Node* x) {
    if(x->right != nullptr) {
        return treeMinimum(x->right);
    }
    Node* y = x->p;
    while(y != nullptr && x == y->right) {
        x = y;
        y = y->p;
    }
    return y;
}

void treeInsert(Tree &T, Node* z) {
    Node* y = nullptr;
    Node* x = T.root;
    while(x != nullptr) {
        y = x;
        if(z->key < x->key) {
            x = x->left;
        }
        else {
            x = x->right;
        }
    }
    z->p = y;
    if(y == nullptr) {
       T.root = z;
    }
    else if(z->key < y->key) {
        y->left = z;
    }
    else {
        y->right = z;
    }
}

void transplant(Tree& T, Node* u, Node* v) {
    if(u->p == nullptr) {
        T.root = v;
    }
    else if(u == u->p->left) {
        u->p->left = v;
    }
    else {
        u->p->right = v;
    }
    if(v != nullptr) {
        v->p = u->p;
    }
}

void treeDelete(Tree& T, Node* z) {
    if(z->left == nullptr) {
        transplant(T, z, z->right);
    }
    else if(z->right == nullptr) {
        transplant(T, z, z->left);
    }
    else {
        Node* y = treeMinimum(z->right);
        if(y->p != z) {
            transplant(T, y, y->right);
            y->right = z->right;
            y->right->p = y;
        }
        transplant(T, z, y);
        y->left = z->left;
        y->left->p = y;
    }
}

int main() {
    Tree T;
    treeInsert(T, new Node(4));
    if(T.root == nullptr) 
        cout << "null\n";
    for(int i = 0; i < 8; ++i) {
        treeInsert(T, new Node(rand() % 20));
    }
    inorderTreeWalk(T.root);
    Node* tmp = treeSearch(T.root, 4);
    if(tmp != nullptr) {
        cout << "Key found : 4" << endl;
    }
    else {
        cout << "Key not found : 4" << endl;
    }

    cout << treeMinimum(T.root)->key << endl;
    cout << treeMaximum(T.root)->key << endl;
    cout << treeSuccessor(tmp)->key << endl;

    treeDelete(T, tmp);
    tmp = iterativeTreeSearch(T.root, 4);
    if(tmp != nullptr) {
        cout << "Key found : 4" << endl;
    }
    else {
        cout << "Key not found : 4" << endl;
    }

    return 0;
}