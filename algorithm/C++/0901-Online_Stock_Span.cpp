class StockSpanner {
public:
    StockSpanner() {
        day = 0;
        myStack.push({day, INT_MAX});
    }
    
    int next(int price) {
        while (price >= myStack.top().second) {
            myStack.pop();
        }
        day ++;
        int time = day - myStack.top().first;
        myStack.push({day, price});
        return time;
    }
private:
    stack<pair<int, int>> myStack;
    int day;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */