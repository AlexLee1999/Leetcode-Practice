class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int i=0; i<nums.size(); ++i) {
            count[nums[i]] ++;
        }
        vector<pair<int, int>> arr;
        for (auto it = count.begin(); it != count.end(); ++it) {
            arr.push_back({it->first, it->second});
        }
        sort(arr.begin(), arr.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if (a.second == b.second) {
                return a.first > b.first;
            } 
            return a.second < b.second; 
        });
        vector<int> ans;
        for (int i=0; i<arr.size(); ++i) {
            for (int j=0; j<arr[i].second; ++j) {
                ans.push_back(arr[i].first);
            }
        }
        return ans;
    }
};
// Time : O(nlogn)
// Space : O(n)