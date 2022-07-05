class MyQueue {
public:
    stack<int> myStack1;
    stack<int> myStack2;
    MyQueue() {
    }
    
    void push(int x) {
        while (!myStack1.empty()) {
            myStack2.push(myStack1.top());
            myStack1.pop();
        }
        myStack1.push(x);
        while (!myStack2.empty()) {
            myStack1.push(myStack2.top());
            myStack2.pop();
        }
    }
    
    int pop() {
        int x = myStack1.top();
        myStack1.pop();
        return x;
    }
    
    int peek() {
        return myStack1.top();
    }
    
    bool empty() {
        return myStack1.empty();
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