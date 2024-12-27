class MyQueue {
public:
    stack<int> st;
    stack<int> rt; // helper stack
    MyQueue() {
        
    }
    
    void push(int x) {// 0(1)
        st.push(x);
    }
    
    int pop() { // O(n)
        // remove at bottom
        while(st.size() > 0) {
            rt.push(st.top());
            st.pop();
        } 
        int x = rt.top();
        rt.pop();
        while(rt.size() > 0) {
            st.push(rt.top());
            rt.pop();
        } 
        return x;
    }
    
    int peek() { // front O(n)
        // retrive at bottom
        while(st.size() > 0) {
            rt.push(st.top());
            st.pop();
        } 
        int x = rt.top();
        while(rt.size() > 0) {
            st.push(rt.top());
            rt.pop();
        } 
        return x;
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