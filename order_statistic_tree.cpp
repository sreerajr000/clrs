#include <bits/stdc++.h>

using namespace std;

const int RED = 0;
const int BLACK = 1;

struct Node {
    int key;
    int color;
    int size;
    Node* p;
    Node* left;
    Node* right;

    Node(int x) : key(x), color(RED), size(1), p(nullptr), left(nullptr), right(nullptr) {}
};

struct Tree {
    Node* root;
    Node* nil;

    Tree() {
        nil = new Node(INT_MIN);
        nil->color = BLACK;
        nil->left = nil->right = nil->p = nil;
        nil->size = 0;
        root = nil;
    }
};


void leftRotate(Tree& T, Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if(y->left != T.nil) {
        y->left->p = x;
    }
    y->p = x->p;
    if(x->p == T.nil) {
        T.root = y;
    }
    else if(x == x->p->left) {
        x->p->left = y;
    }
    else {
        x->p->right = y;
    }
    y->left = x;
    x->p = y;
    y->size = x->size;
    x->size = x->left->size + x->right->size + 1;
}

void rightRotate(Tree& T, Node* x) {
    Node* y = x->left;
    x->left = y->right;
    if(y->right != T.nil) {
        y->right->p = x;
    }
    y->p = x->p;
    if(x->p == T.nil) {
        T.root = y;
    }
    else if(x == x->p->right) {
        x->p->right = y;
    }
    else {
        x->p->left = y;
    }
    y->right = x;
    x->p = y;

    y->size = x->size;
    x->size = x->left->size + x->right->size + 1;
}

void rbInsertFixup(Tree& T, Node* z) {
    while(z->p->color == RED) {
        if(z->p == z->p->p->left) {
            Node* y;
            y = z->p->p->right;
            if(y->color == RED) {
                z->p->color = BLACK;
                y->color = BLACK;
                z->p->p->color = RED;
                z = z->p->p;
            }
            else { 
                if(z == z->p->right) {
                    z = z->p;
                    leftRotate(T, z);
                }
                z->p->color = BLACK;
                z->p->p->color = RED;
                rightRotate(T, z->p->p);
            }
        }
        else {
            Node* y;
            y = z->p->p->left;
            if(y->color == RED) {
                z->p->color = BLACK;
                y->color = BLACK;
                z->p->p->color = RED;
                z = z->p->p;
            }
            else { 
                if(z == z->p->left) {
                    z = z->p;
                    rightRotate(T, z);
                }
                z->p->color = BLACK;
                z->p->p->color = RED;
                leftRotate(T, z->p->p);
            }
        }
    }
    T.root->color = BLACK;
}

void rbInsert(Tree& T, Node* z) {
    Node* y = T.nil;
    Node* x = T.root;
    while(x != T.nil) {
        y = x;
        ++x->size;
       if(z->key < x->key) { 
            x = x->left;
        }
        else {
            x = x->right;
        }
    }
    z->p = y;
    if(y == T.nil) {
        T.root = z;
    }
    else if(z->key < y->key) {
        y->left = z;
    }
    else {
        y->right = z;
    }
    z->left = T.nil;
    z->right = T.nil;
    z->color = RED;
    rbInsertFixup(T, z);
}

void rbTransplant(Tree& T, Node* u, Node* v) {
    if(u->p == T.nil) {
        T.root = v;
    }
    else if(u == u->p->left) {
        u->p->left = v;
    }
    else {
        u->p->right = v;
    }
    v->p = u->p;
}

Node* treeMinimum(Tree&T, Node* x) {
    while(x->left != T.nil) {
        x = x->left;
    }
    return x;
}

Node* treeMaximum(Tree& T, Node* x) {
    while(x->right != T.nil) {
        x = x->right;
    }
    return x;
}

Node* treeSearch(Tree& T, Node* x, int k) {
    if(x == T.nil || k == x->key) {
        return x;
    }
    if(k < x->key) {
        return treeSearch(T, x->left, k);
    }
    return treeSearch(T, x->right, k);
}

void rbDeleteFixup(Tree& T, Node* x) {
    while(x != T.root && x->color == BLACK) {
        if(x == x->p->left) {
            Node* w = x->p->right;
            if(w->color == RED) {
                w->color = BLACK;
                x->p->color = RED;
                leftRotate(T, x->p);
            }
            if(w->left->color == BLACK && w->right->color == BLACK) {
                w->color = RED;
                x = x->p;
            }
            else {
                if(w->right->color == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(T, w);
                    w = x->p->right;
                }
                w->color = x->p->color;
                x->p->color = BLACK;
                w->right->color = BLACK;
                leftRotate(T, x->p);
                x = T.root;
            }
        }
        else {
            Node* w = x->p->left;
            if(w->color == RED) {
                w->color = BLACK;
                x->p->color = RED;
                rightRotate(T, x->p);
            }
            if(w->right->color == BLACK && w->left->color == BLACK) {
                w->color = RED;
                x = x->p;
            }
            else {
                if(w->left->color == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(T, w);
                    w = x->p->left;
                }
                w->color = x->p->color;
                x->p->color = BLACK;
                w->left->color = BLACK;
                rightRotate(T, x->p);
                x = T.root;
            }
        }
        x->color = BLACK;
    }
}

void updateSize(Tree& T, Node* z) {
    Node* x = z;
    while(x != T.nil) {
        cout << "key : " << x->key <<endl;
        --x->size;
        x = x->p;
    }
}

void rbDelete(Tree& T, Node* z) {
    updateSize(T, z);
    Node* y = z;
    Node* x;
    int yOriginalColor = y->color;
    if(z->left == T.nil) {
        x = z->right;
        rbTransplant(T, z, z->right);
    }
    else if(z->right == T.nil) {
        x = z->left;
        rbTransplant(T, z, z->left);
    }
    else {
        y = treeMinimum(T, z->right);
        yOriginalColor = y->color;
        x = y->right;
        if(y->p == z) {
            x->p = y;
        }
        else {
            rbTransplant(T, y, y->right);
            y->right = z->right;
            y->right->p = y;
        }
        rbTransplant(T, z, y);
        y->left = z->left;
        y->left->p = y;
        y->color = z->color;
    }
    if(yOriginalColor == BLACK) {
        rbDeleteFixup(T, x);
    }
}

Node* osSelect(Node* x, int i) {
    int r = x->left->size + 1;
    if(i == r) {
        return x;
    }
    else if(i < r) {
        return osSelect(x->left, i);
    }
    else {
        return osSelect(x->right, i - r);
    }
}

int osRank(Tree& T, Node* x) {
    int r = x->left->size + 1;
    Node* y = x;
    while(y != T.root) {
        if(y == y->p->right) {
            r = r + y->p->left->size + 1;
        }
        y = y->p;
    }
    return r;
}

void inorderTreeWalk(Tree& T, Node* x) {
    if(x != T.nil) {
        inorderTreeWalk(T, x->left);
        cout << x->key << ", "; 
        inorderTreeWalk(T, x->right);
    }
}

void levelOrderWalk(Tree& T, Node *root) 
{ 
    if (root == T.nil) 
        return; 
  
    queue<Node *> q; 
    q.push(root); 
  
    while (!q.empty()) 
    { 
        Node *temp = q.front(); 
        cout << temp->key << " ";
        q.pop(); 
  
        if (temp->left != T.nil) 
            q.push(temp->left); 
  
        if (temp->right != T.nil) 
            q.push(temp->right); 
    } 
} 

int main() {
    Tree T;
    rbInsert(T, new Node(4));
    if(T.root == nullptr) 
        cout << "null\n";
    for(int i = 0; i < 8; ++i) {
        rbInsert(T, new Node(rand() % 20));
    }
    inorderTreeWalk(T, T.root);
    cout << endl;
    levelOrderWalk(T, T.root);
    cout << endl;
    Node* tmp = treeSearch(T, T.root, 4);
    if(tmp != T.nil) {
        cout << "Key found : 4" << endl;
    }
    else {
        cout << "Key not found : 4" << endl;
    }

    cout << treeMinimum(T, T.root)->key << endl;
    cout << treeMaximum(T, T.root)->key << endl;

    cout << osSelect(T.root, 8)->key << endl;
    cout << osRank(T, tmp) << endl;
    return 0;
}