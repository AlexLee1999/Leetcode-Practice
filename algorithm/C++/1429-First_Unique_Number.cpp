class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        for (int i=0; i<nums.size(); ++i) {
            arr.push_back(nums[i]);
            myMap[nums[i]] ++;
        }
        idx = 0;
    }
    
    int showFirstUnique() {
        while (idx < arr.size() && myMap[arr[idx]] > 1) {
            idx ++;
        } 
        if (idx == arr.size()) {
            return -1;
        }
        return arr[idx];
    }
    
    void add(int value) {
        arr.push_back(value);
        myMap[value] ++;
    }
private:
    unordered_map<int, int> myMap;
    vector<int> arr;
    int idx;
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */