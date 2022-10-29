class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> left(security.size(), 0);
        vector<int> right(security.size(), 0);
        vector<int> ans;
        for (int i=1; i<security.size(); ++i) {
            if (security[i] <= security[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }
        for (int i=security.size() - 2; i>= 0; --i) {
            if (security[i] <= security[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
        }
        for (int i=0; i<left.size(); ++i) {
            if (left[i] >= time && right[i] >= time) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(n)