class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        short n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (short i = 0 ;i < n; ++i) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 and nums[i] == nums[i-1]) {
                continue;
            }
            short j = i + 1;
            short k = n - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] < 0) {
                    j++;
                }
                else if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                }
                else {
                    int b = nums[j];
                    int c = nums[k];
                    vector<int> ans {nums[i], nums[j], nums[k]};
                    res.push_back(ans);
                    while (j < k && nums[j] == b) {
                        j++;
                    }
                    while (j < k && nums[k] == c) {
                        k--;
                    }
                }
            }
        }
        return res;
    }
};
