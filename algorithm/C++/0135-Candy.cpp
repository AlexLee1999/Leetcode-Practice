class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> right(ratings.size(), 1);
        vector<int> left(ratings.size(), 1);
        int ans = 0;
        for (int i=1; i<ratings.size(); ++i) {
            if (ratings[i] > ratings[i-1]) {
                left[i] = left[i-1] + 1;
            }
        }
        for (int i=ratings.size() - 1; i > 0; --i) {
            if (ratings[i-1] > ratings[i]) {
                right[i-1] = right[i] + 1;
            }
        }
        for (int i=0; i<ratings.size(); ++i) {
            ans += max(right[i], left[i]);
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(n)