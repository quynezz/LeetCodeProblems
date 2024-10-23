class MyStack { 
private: 
queue<int> q1;
queue<int> q2;
public:
    MyStack() { 
    }
    void push(int x) { 
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        } 
        swap(q1,q2);
    }
    
    int pop() {
        if(q1.empty()){ 
            return 0;
        } 
        int val = q1.front();  
        q1.pop();
        return val;
    }
    
    int top() { 
        if(q1.empty()){  
            return 0;
        }
        int val = q1.front();
        return val;
    }
    
    bool empty() {
        return q1.empty();
    }






// private: 
// list<int> l;
// public:
//     MyStack() { 
//     }
//     void push(int x) { 
//         l.push_back(x);    
//     }
    
//     int pop() {
//         if(l.empty()){ 
//             return 0;
//         } 
//         int val = l.back();  
//         l.pop_back();
//         return val;
//     }
    
//     int top() { 
//         if(l.empty()){  
//             return 0;
//         }
//         int val = l.back();
//         return val;
//     }
    
//     bool empty() {
//         if(l.empty()){
//             return true;
//         }else{
//             return false;
//         }
//     }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */