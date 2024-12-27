class MyQueue {
public:
    stack<int> st;
    stack<int> rt; // helper stack
    MyQueue() {
        
    }
    
    void push(int x) {// 0(n)
        // push at bottom
        if(st.size() == 0) {
            st.push(x);
            return;
        } else {
            while(st.size() > 0 ) {
                rt.push(st.top());
                st.pop();
            }
            st.push(x);
            while(rt.size()>0) {
                st.push(rt.top());
                rt.pop();
            } 
        }
    }
    
    int pop() { // O(1)
        int x = st.top();
        st.pop();
        return x;
    }
    
    int peek() { // front O(1)
        // retrive at bottom
        return st.top();
    }
    
    bool empty() {
        if(st.size() == 0 ) return true;
        else return false;
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