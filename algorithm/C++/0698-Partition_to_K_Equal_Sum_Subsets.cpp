class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int i=0; i<nums.size(); ++i) {
            sum += nums[i];
        }
        if (sum % k != 0) {
            return false;
        }
        int target = sum / k;
        sort(nums.begin(), nums.end(), greater<int>());
        return backtrack(nums, k, target, 0, 0, 0, 0);
    }
    bool backtrack(vector<int>& nums, int k, int target, int visited, int cur, int count, int index) {
        if (count == k - 1) {
            return true;
        }
        if (cur == target) {
            return backtrack(nums, k, target, visited, 0, count + 1, 0);
        }
        if (cur > target) {
            return false;
        }
        for (int i=index; i<nums.size(); ++i) {
            if (!((visited >> i) & 1)) {
                int tmp = visited;
                visited = (visited | (1 << i));
                if (backtrack(nums, k, target, visited, cur + nums[i], count, i + 1)) {
                    return true;
                }
                visited = tmp;
            }
        }
        return false;
    }
};