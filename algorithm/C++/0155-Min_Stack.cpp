class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (myStack.empty()) {
            myStack.push({val, val});
            return;
        }
        int cur_min = min(myStack.top().second, val);
        myStack.push({val, cur_min});
        return;
    }
    
    void pop() {
        myStack.pop();
        return;
    }
    
    int top() {
        return myStack.top().first;
    }
    
    int getMin() {
        return myStack.top().second;
    }
private:
    stack<pair<int, int>> myStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// Time : O(1) for all operations
// Space : O(n)