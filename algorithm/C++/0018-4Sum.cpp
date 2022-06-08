class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        if (n < 4) {
		    return res;
	    }
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; ++i) {

            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) {
                break;
            }
            if (nums[i] + nums[n-3] + nums[n-2] + nums[n-1] < target) {
                continue;
            }
            for (int j = i + 1; j < n - 2; ++j) {

                if (j > i + 1 && nums[j] == nums[j-1]) {
                    continue;
                }
                if (nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) {
                    break;
                }
                if (nums[i] + nums[j] + nums[n-2] + nums[n-1] < target) {
                    continue;
                }
                int left = j + 1;
                int right = n - 1;
                while (left < right) {
                    int tempSum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (tempSum == target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        int originLeft = nums[left];
                        int originRight = nums[right];
                        while (left < right && nums[left] == originLeft) {
                            ++left;
                        }
                        while (right > left && nums[right] == originRight) {
                            --right;
                        }
                    }
                    else if (tempSum > target) {
                        --right;
                    }
                    else {
                        ++left;
                    }
                }
            }
        }
        return res;
    }
};
// Time : O(n^3)
// Space : O(n)