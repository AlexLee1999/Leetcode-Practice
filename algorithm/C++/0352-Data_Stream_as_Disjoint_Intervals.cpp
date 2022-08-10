class SummaryRanges {
public:
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        if (myMap.empty()) {
            myMap[val] = val;
            return;
        }
        auto it = myMap.lower_bound(val);
        if (it == myMap.end()) {
            it --;
            if (it->second == val - 1) {
                it->second = val;
            } else if (it->second < val - 1){
                myMap[val] = val;
            }
        } else if (it == myMap.begin()) {
            if (it->first == val + 1) {
                myMap[val] = it->second;
                myMap.erase(it->first);
            } else if (it->first > val + 1){
                myMap[val] = val;
            }
        } else {
            auto prev_it = prev(it);
            if (it->first == val + 1 && prev_it->second == val - 1) {
                prev_it->second = it->second;
                myMap.erase(it->first);
            } else if (it->first == val + 1) {
                myMap[val] = it->second;
                myMap.erase(it->first);
            } else if (prev_it->second == val - 1) {
                prev_it->second = val;
            } else if (prev_it->second < val - 1 && it->first > val + 1) {
                myMap[val] = val;
            }
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for (auto it = myMap.begin(); it != myMap.end(); ++it) {
            ans.push_back({it->first, it->second});
        }
        return ans;
    }
private:
    map<int, int> myMap; // myMap[left] = right
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */