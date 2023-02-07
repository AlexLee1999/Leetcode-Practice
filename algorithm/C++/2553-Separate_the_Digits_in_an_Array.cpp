class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> arr;
        vector<int> ans;
        for (int i=0; i<nums.size(); ++i) {
            arr = separate(nums[i]);
            ans.insert(ans.end(), arr.begin(), arr.end());
        }
        return ans;
    }
    vector<int> separate(int n) {
        vector<int> arr;
        while (n > 0) {
            arr.push_back(n % 10);
            n /= 10;
        }
        reverse(arr.begin(), arr.end());
        return arr;
    }
};