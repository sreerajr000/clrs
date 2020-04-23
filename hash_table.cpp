#include <bits/stdc++.h>

using namespace std;

const int NIL = INT_MIN;

int h(int k, int i, int m) {
    return ((k % m) + i) % m; //linear probing
}

int hashInsert(vector<int>& T, int k) {
    int m = T.size();
    int i = 0;
    do {
        int j = h(k, i, m);
        if(T[j] == NIL) {
            T[j] = k;
            return j;
        }
        else {
            ++i;
        }
    }while(i <= m);
    throw overflow_error("Hash table overflow");
}

int hashSearch(vector<int>& T, int k) {
    int i = 0, j;
    int m = T.size();
    do {
        j = h(k, i, m);
        if(T[j] == k) {
            return j;
        }
        ++i;
    }while(T[j] != NIL && i <= m);
    return NIL;
}


int main() {
    vector<int> table(10, NIL);
    hashInsert(table, 4);
    for(int i = 0; i < 11; ++i) {
        try{
            hashInsert(table, rand() % 100);
        }
        catch(const exception &e) {
            cout << e.what() << endl;
        }
    }

    cout << hashSearch(table, 24) << endl;
    cout << hashSearch(table, 4) << endl;

    for(int i = 0; i < table.size(); ++i) {
        cout << i << " : " << table[i] << endl;
    }

    return 0;
}