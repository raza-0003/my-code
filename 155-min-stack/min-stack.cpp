class MinStack {
public:
    stack<long long>st;
    long long mini = LLONG_MAX;
    MinStack() {
    }
    
    void push(int val) {
        long long x = val;
        if(st.empty()){
            mini = x;
            st.push(x);
        }
        else{
            if(x>=mini){
                st.push(x);
            }
            else{
                st.push(2LL * x - mini);
                mini = x;
            }

        }
        
    }
    
    void pop() {
        if(st.empty()) return;
        long long x = st.top();
        st.pop();
        if(x<mini){ //that means it is modified min so we need to get previous min
            mini = 2*mini-x;
            }  
    }
    
    int top() {
         if(st.empty()) return -1;
         long long x = st.top();
         if(x<mini) return mini;
         return x;
        
    }
    
    int getMin() {
        if(st.empty()) return -1;
        return mini;
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