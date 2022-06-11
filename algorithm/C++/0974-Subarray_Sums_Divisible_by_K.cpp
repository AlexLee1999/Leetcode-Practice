class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0;
        int count = 0;
        unordered_map<int, int> myMap;
        myMap[0] ++;
        for (int i=0; i<nums.size(); ++i) {
            sum += nums[i];
            sum %= k;
            if (sum < 0) {
                sum += k;
            }
            count += myMap[sum];
            myMap[sum] ++;
        }
        return count;
    }
};
// Time : O(n)
// Space : O(n)
// Prefix(0~i-1) = km + r1
// Prefix(0~j) = kn + r2
// subarr(i~i) = k(n-m) + r2-r1
// Therefore if r2 == r1, the subarr is divisible by k