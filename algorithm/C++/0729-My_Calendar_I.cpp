class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = myMap.upper_bound(start); // find the end of next interval
        if (it != myMap.end() && it->second < end) {
            return false;
        }
        myMap[end] = start;
        return true;
    }
private:
    map<int, int> myMap;
};
// Time : O(logn)