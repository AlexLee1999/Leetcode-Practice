class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> myMap;
        unordered_set<int> mySet;
        int nums = 0;
        for (int i=0; i<s.size(); ++i) {
            myMap[s[i]] ++;
        }
        for (auto it=myMap.begin(); it != myMap.end(); ++it) {
            int count = it->second;
            while (count > 0 && mySet.find(count) != mySet.end()) {
                count --;
                nums ++;
            }
            if (count > 0) {
                mySet.insert(count);
            }
        }
        return nums;
    }
};
// Time : O(n + k^2) k is the number of frequencies 
// Space : O(n)