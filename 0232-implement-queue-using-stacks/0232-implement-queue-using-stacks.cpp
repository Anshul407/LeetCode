class MyQueue {

private:
    stack<int> s1; // Primary stack
    stack<int> s2; // Secondary stack for transfers
    int front; // Tracks the front element for peek operations

public:
    MyQueue() { }
    
    void push(int x) {
        if (s1.empty()) {
            front = x; // Update front when the first stack is empty
        }
        s1.push(x);
    }
    
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }
    
    int peek() {
        return !s2.empty() ? s2.top() : front;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
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