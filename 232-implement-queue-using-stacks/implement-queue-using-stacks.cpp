class MyQueue {
public:
    stack<int>st1;
    stack<int>st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        //step1
        while(st1.size()){
            st2.push(st1.top());
            st1.pop();
        }
        // step 2
        st1.push(x);
        //step 3
        while(st2.size()){
            st1.push(st2.top());
            st2.pop();
        }
        
    }
    
    int pop() {
        if(st1.empty()) return -1;
        int poppedElem = st1.top();
        st1.pop();
        return poppedElem;
    }
    
    int peek() {
        if(st1.empty()) return -1;
        return st1.top();
    }
    
    bool empty() {
        return st1.empty();
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */