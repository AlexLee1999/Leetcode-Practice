class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        freq[start] ++;
        freq[end] --;
        int count = 0;
        int max_event = 0;
        for (auto it=freq.begin(); it != freq.end(); ++it) {
            count += it->second;
            max_event = max(max_event, count);
        }
        return max_event;
    }
private:
    map<int, int> freq;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */