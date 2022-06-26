class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> myMap;
        unordered_set<int> mySet;
        for (int i=0; i<arr.size(); ++i) {
            myMap[arr[i]] ++;
        }
        for (auto it=myMap.begin(); it != myMap.end(); ++it) {
            if (mySet.count(it->second)) {
                return false;
            }
            mySet.insert(it->second);
        }
        return true;
    }
};
// Time : O(n)
// Space : O(n)