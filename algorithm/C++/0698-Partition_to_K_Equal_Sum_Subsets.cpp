class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();
        // sort(nums.begin(), nums.end());
        for (int i=0; i<n; ++i) {
            sum += nums[i];
        }
        if (sum % k != 0 || n < k) {
            return false;
        }
        vector<bool> visited (n, false);
        return backtrack(nums, k, sum/k, visited, 0, 0, 0);
        
    }
    bool backtrack(vector<int>& nums, int k, int target, vector<bool>& visited, int count, int current, int index) {
        if (count == k-1) {
            return true; //return true if k-1 has grouped
        }
        if (current > target) {
            return false; 
        }
        if (current == target) {
            return backtrack(nums, k, target, visited, count + 1, 0, 0); // find the next subgroup
        }
        for (int i = index; i<nums.size(); ++i) {
            if (!visited[i]) {
                visited[i] = true;
                if (backtrack(nums, k, target, visited, count, current + nums[i], i + 1)) {
                    return true; //if use nums[i] 
                }
                visited[i] = false;
            }
        }
        return false;
    }
};