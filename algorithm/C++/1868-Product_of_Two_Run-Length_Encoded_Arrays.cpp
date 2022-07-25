class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        int ptr1 = 0;
        int ptr2 = 0;
        vector<vector<int>> ans;
        while (ptr1 < encoded1.size() && ptr2 < encoded2.size()) {
            int product = encoded1[ptr1][0] * encoded2[ptr2][0];
            int frequency = min(encoded1[ptr1][1], encoded2[ptr2][1]);
            encoded1[ptr1][1] -= frequency;
            encoded2[ptr2][1] -= frequency;
            if (ans.empty() || ans.back()[0] != product) {
                ans.push_back({product, frequency});
            } else {
                ans.back()[1] += frequency;
            }
            if (encoded1[ptr1][1] == 0) {
                ptr1 ++;
            }
            if (encoded2[ptr2][1] == 0) {
                ptr2 ++;
            }
        }
        return ans;
    }
};
// Time : O(n + m)
// Space : O(1)