#include <bits/stdc++.h>

using namespace std;

class Stack {
    private:
    vector<int> stack;
    int top;

    public:
    Stack() {
        top = 0;
    }

    bool empty() {
        if(top == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    void push(int x) {
        ++top;
        if(stack.size() >= top) {
            stack[top - 1] = x;
        } 
        else {
            stack.push_back(x);
        }
    }

    int pop() {
        if(empty()) {
            throw underflow_error("underflow");
        }
        else {
            --top;
            return stack[top];
        }
    }
};


int main() {
    Stack st;
    cout << st.empty() << endl;
    try {
        cout << st.pop() << endl;
    }
    catch(const exception &e) {
        cout << e.what() << endl;
    }
    st.push(4);
    cout << st.pop() << endl;
    st.push(6);
    cout << st.pop() << endl;
    return 0;
}