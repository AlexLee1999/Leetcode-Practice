class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b){
            if (a[0] != b[0]) {
                return a[0]< b[0]; 
            } else {
                return a[1] > b[1];
            }
        });
        int n = envelopes.size();
        vector<int> height;
        for (int i=0; i<n; ++i) {
            height.push_back(envelopes[i][1]);
        }
        return LIS(height);
    }
    int LIS(vector<int>& height) {
        int n = height.size();
        vector<int> seq;
        for (int i=0; i<n; ++i) {
            auto it = lower_bound(seq.begin(), seq.end(), height[i]);
            if (it == seq.end()) {
                seq.push_back(height[i]);
            } else {
                *it = height[i];
            }
        }
        return seq.size();
    }
};