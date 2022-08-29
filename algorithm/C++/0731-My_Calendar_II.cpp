class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for (auto it = double_book.begin(); it != double_book.end(); ++it) {
            if (!(it->second <= start || it->first >= end)) {
                return false;
            }
        }
        for (auto it = single_book.begin(); it != single_book.end(); ++it) {
            if (!(it->second <= start || it->first >= end)) {
                double_book.insert({max(start, it->first), min(end, it->second)});
            }
        }
        single_book.insert({start, end});
        return true;
    }
    
private:
    set<pair<int, int>> single_book;
    set<pair<int, int>> double_book;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */