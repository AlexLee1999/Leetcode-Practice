class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> mySet;
        int num = 0;
        for (int i=0; i<jewels.size(); ++i) {
            mySet.insert(jewels[i]);
        }
        for (int i=0; i<stones.size(); ++i) {
            if (mySet.count(stones[i])) {
                num ++;
            }
        }
        return num;
    }
};
// Time : O(n+m) n = stones
// Space : O(m) m = jewels