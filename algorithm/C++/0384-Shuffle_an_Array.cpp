class Solution {
public:
    Solution(vector<int>& nums) {
        arr = nums;
        
    }
    
    vector<int> reset() {
        return arr;
    }
    
    vector<int> shuffle() {
        vector<int> shuffle_arr(arr.begin(), arr.end());
        int n = arr.size();
        for (int i=n - 1; i>=0; --i) {
            int r = rand() % (i + 1);
            swap(shuffle_arr[i], shuffle_arr[r]);
        }
        return shuffle_arr;
    }
private:
    vector<int> arr;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// Time : O(n)
// Space : O(n)

/* Fisher Yates Algorithm */ 