class MyCircularQueue {
    int f; // front
    int b; // back / rear
    int s; // current size
    int c; // capacity
    vector<int> arr; // 
    public : MyCircularQueue(int k) { // k is capacity
        f = 0;
        b = 0;
        s = 0;
        c = k;
        vector<int> v(k);
        arr = v;
    }
    
    bool enQueue(int val) { // push
        if(s==c) return false;
        arr[b] = val;
        b++;
        if(b==c) b = 0; // imp
        s++;
        return true;
    }
    
    bool deQueue() { // pop front
        if(s == 0) return false;
        f++;
        if(f == c) f = 0; // imp
        s--;
        return true;
    }
    
    int Front() {
        if(s==0) return -1;
        return arr[f];
    }
    
    int Rear() { // back
        if(s == 0) return -1;
        if(b==0) return arr[c-1]; // imp
        return arr[b-1];
    }
    
    bool isEmpty() {
        if(s==0) return true;
        else return false;
    }
    
    bool isFull() {
        if(s==c) return true;
        else return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * boolean param_1 = obj.enQueue(value);
 * boolean param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * boolean param_5 = obj.isEmpty();
 * boolean param_6 = obj.isFull();
 */