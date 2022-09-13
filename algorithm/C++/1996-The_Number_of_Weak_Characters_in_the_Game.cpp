class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size();
        sort(properties.begin(), properties.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        int current_max = properties[n - 1][1];
        int ans = 0;
        for (int i=n - 2; i >= 0; --i) {
            if (properties[i][1] < current_max) {
                ans ++;
            }
             current_max = max(current_max, properties[i][1]);
        }
        return ans;
    }
};
// Time : O(nlogn)
// Space : O(1)