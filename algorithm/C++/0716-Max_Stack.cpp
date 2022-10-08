class MaxStack {
public:
    MaxStack() {
        count = 0;
    }
    
    void push(int x) {
        stack.insert({count, x});
        maxTree.insert({x, count});
        count ++;
    }
    
    int pop() {
        pair<int, int> value = *stack.rbegin();
        stack.erase(value);
        maxTree.erase({value.second, value.first});
        return value.second;
    }
    
    int top() {
        pair<int, int> value = *stack.rbegin();
        return value.second;
    }
    
    int peekMax() {
        pair<int, int> value = *maxTree.rbegin();
        return value.first;
    }
    
    int popMax() {
        pair<int, int> value = *maxTree.rbegin();
        maxTree.erase(value);
        stack.erase({value.second, value.first});
        return value.first;
    }
private:
    set<pair<int, int>> stack;
    set<pair<int, int>> maxTree;
    int count;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */