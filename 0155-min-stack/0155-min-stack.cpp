class MinStack {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    vector<int>st;
    MinStack() {
        
    }
    
    void push(int val) {
       
        pq.push(val);
        st.push_back(val);
    }
    
    void pop() {
       
       int x=st.back();
       st.pop_back();
       vector<int>temp;
       while(!pq.empty()){
            if(x==pq.top()){pq.pop();break;}
            else temp.push_back(pq.top());
            pq.pop();
       }
       for(auto ii:temp)pq.push(ii);

    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        
        return pq.top();
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