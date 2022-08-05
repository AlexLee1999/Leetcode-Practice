class Solution {
public:
    Solution(int n, vector<int>& blacklist) {
        unordered_set<int> mySet;
        num = n - blacklist.size(); // whitelist length
        for (int i=num; i<n; ++i) {
            mySet.insert(i);
        }
        for (int i=0; i<blacklist.size(); ++i) {
            mySet.erase(blacklist[i]);
        }
        auto it = mySet.begin();
        for (int i=0; i<blacklist.size(); ++i) {
            if (blacklist[i] < num) {
                myMap[blacklist[i]] = *it; // map the blacklist to whitelist item which is larger than num
                it ++;
            }
        }
    }
    
    int pick() {
        int ran = rand() % num;
        return myMap.count(ran) ? myMap[ran] : ran;
    }
private:
    unordered_map<int, int> myMap;
    int num;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */