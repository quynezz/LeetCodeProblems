class MyQueue {
private:
list<int> l;
public:
    MyQueue() {
        
    }
    
    void push(int x) { 
        l.push_back(x);

    }
    
    int pop() {
       int pop = l.front();
       l.pop_front();
       return pop;
    }
    
    int peek() {
        int p = l.front();
        return p;
    }
    
    bool empty() { 
        return !l.empty() ? false : true;
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