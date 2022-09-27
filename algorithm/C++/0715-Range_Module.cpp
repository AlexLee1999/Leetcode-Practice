class RangeModule {
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        if (range.empty()) {
            range[left] = right;
            return;
        }
        auto it = range.upper_bound(left);
        if (it != range.begin()) {
            it --;
        } 
        int l = left;
        int r = right;
        while (it != range.end() && it->first <= r) {
            if (it->second >= l) {
                l = min(l, it->first);
                r = max(r, it->second);
                range.erase(it ++);
            } else {
                it ++;
            }
        }
        range[l] = r;
        return;
    }
    
    bool queryRange(int left, int right) {
        if (range.empty()) {
            return false;
        }
        auto it = range.upper_bound(left);
        if (it != range.begin()) {
            it --;
        } else {
            return false;
        }
        if (it->second >= right) {
            return true;
        }
        return false;
    }
    
    void removeRange(int left, int right) {
        if (range.empty()) {
            return;
        }
        auto it = range.upper_bound(left);
        if (it != range.begin()) {
            it --;
        } 
        while (it != range.end() && right > it->first) {
                
            if (it->second > right) {
                range[right] = it->second;
            } 
            if (it->first < left) {
                it->second = min(it->second, left);
                it ++;
            } else {
                range.erase(it ++);
            }
        }
    }
private:
    map<int, int> range;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */