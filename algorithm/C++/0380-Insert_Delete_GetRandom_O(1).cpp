class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (myMap.find(val) != myMap.end()) {
            return false;
        }
        arr.push_back(val);
        myMap[val] = arr.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (myMap.find(val) == myMap.end()) {
            return false;
        }
        int idx = myMap[val];
        int last_val = arr.back();
        arr[idx] = last_val;
        myMap[last_val] = idx;
        arr.pop_back();
        myMap.erase(val);
        return true;
    }
    
    int getRandom() {
        int ran = rand() % arr.size();
        return arr[ran];
    }
private:
    unordered_map<int, int> myMap;
    vector<int> arr;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */