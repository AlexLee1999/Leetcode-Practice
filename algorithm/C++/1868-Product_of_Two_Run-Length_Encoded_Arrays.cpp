class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        int ptr1 = 0;
        int ptr2 = 0;
        vector<vector<int>> ans;
        while (ptr1 < encoded1.size() && ptr2 < encoded2.size()) {
            int product = encoded1[ptr1][0] * encoded2[ptr2][0];
            int min_freq = min(encoded1[ptr1][1], encoded2[ptr2][1]);
            encoded1[ptr1][1] -= min_freq;
            encoded2[ptr2][1] -= min_freq;
            if (encoded1[ptr1][1] == 0) {
                ptr1 ++;
            }
            if (encoded2[ptr2][1] == 0) {
                ptr2 ++;
            }
            if (ans.empty() || ans.back()[0] != product) {
                ans.push_back({product, min_freq});
            } else {
                ans.back()[1] += min_freq;
            }
        }
        return ans;
    }
};