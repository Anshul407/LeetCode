class MyStack {
public:
    queue<int>q;
    int rear,front;
    MyStack() {
        rear=0;
        front=0;
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        if(q.empty())return -1;
        vector<int>cur;
        while(!q.empty()){
            cur.push_back(q.front());
            q.pop();
        }
        
        auto x=cur.back();
        cur.pop_back();
        for(auto i:cur)q.push(i);
        return x;
    }
    
    int top() {
        if(q.empty())return -1;
        vector<int>cur;
        while(!q.empty()){
            cur.push_back(q.front());
            q.pop();
        }
        
        auto x=cur.back();
       
        for(auto i:cur)q.push(i);
        
        return x;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */