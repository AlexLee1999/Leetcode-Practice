class TwoSum {
public:
    TwoSum() {}
    
    void add(int number) {
        myMap[number] ++;
    }
    
    bool find(int value) {
        for (auto it = myMap.begin(); it != myMap.end(); ++it) {
            long complement = (long)value - it->first;
            if (complement != it->first) {
                if (myMap.find(complement) != myMap.end()) {
                    return true;
                }
            } else {
                if (it ->second >= 2) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    unordered_map<int, int> myMap;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */