class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        while (!myQueue1.empty()) {
            myQueue2.push(myQueue1.front());
            myQueue1.pop();
        }
        myQueue1.push(x);
        while (!myQueue2.empty()) {
            myQueue1.push(myQueue2.front());
            myQueue2.pop();
        }
    }
    
    int pop() {
        int x = myQueue1.front();
        myQueue1.pop();
        return x;
    }
    
    int top() {
        return myQueue1.front();
    }
    
    bool empty() {
        return myQueue1.empty();
    }
private:
    queue<int> myQueue1;
    queue<int> myQueue2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */