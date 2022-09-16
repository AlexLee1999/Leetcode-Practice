class RandomizedCollection {
public:
    RandomizedCollection() {

    }
    
    bool insert(int val) {
        if (myMap[val].empty()) {
            arr.push_back(val);
            myMap[val].insert(arr.size() - 1);
            return true;
        }
        arr.push_back(val);
        myMap[val].insert(arr.size() - 1);
        return false;
    }
    
    bool remove(int val) {
        if (myMap[val].empty()) {
            return false;
        }
        if (arr.back() == val) {
            myMap[val].erase(arr.size() - 1);
            arr.pop_back();
            return true;
        }
        int idx = *myMap[val].begin();
        int idxBack = arr.size() - 1;
        myMap[val].erase(idx);
        int back_val = arr.back();
        myMap[back_val].erase(idxBack);
        myMap[back_val].insert(idx);
        arr[idx] = arr.back();
        arr.pop_back();
        return true;
    }
    
    int getRandom() {
        int ran = rand() % arr.size();
        return arr[ran];
    }
private:
    vector<int> arr;
    unordered_map<int, unordered_set<int>> myMap;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
