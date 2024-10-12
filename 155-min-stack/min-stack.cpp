#include<bits/stdc++.h>  // Include libraries
using namespace std;     // Use standard namespace

class MinStack {
public:
    stack<pair<int,int>> st; // Member variable for the stack

    MinStack() {
        // Constructor body (empty in this case)
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push({val, val});
        }
        else {
            st.push({val, min(val, st.top().second)}); // Push with updated minimum
        }
    }
    
    void pop() {
        st.pop();  // Pop the top element from the stack
    }
    
    int top() {
        return st.top().first;  // Access the value of the top element
    }
    
    int getMin() {
        return st.top().second; // Access the minimum value stored in the top element
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */