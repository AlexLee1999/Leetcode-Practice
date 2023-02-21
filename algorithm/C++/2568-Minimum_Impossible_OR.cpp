class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_set<int> mySet(nums.begin(), nums.end());
        int n = 1;
        for (int i=0; i<32; ++i) {
            if (!mySet.count(n)) {
                return n;
            }
            n <<= 1;
        }
        return -1;
    }
};
