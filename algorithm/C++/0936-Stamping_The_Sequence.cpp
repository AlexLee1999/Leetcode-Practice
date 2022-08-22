class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int s = stamp.size();
        int t = target.size();
        int modified = 0;
        vector<bool> visited(t, false);
        vector<int> ans;
        while (modified < t) {
            bool stamped = false;
            for (int i=0; i<=t-s; ++i) {
                if (!visited[i] && match(i, stamp, target)) {
                    visited[i] = true;
                    ans.push_back(i);
                    stamped = true;
                    replace(i, stamp, target, modified);
                }
            }
            if (!stamped) {
                return {};
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void replace(int idx, string& stamp, string& target, int& modified) {
        for (int i=0; i<stamp.size(); ++i) {
            if (target[i + idx] != '?') {
                modified ++;
                target[i + idx] = '?';
            }
        }
    }
    bool match(int idx, string& stamp, string& target) {
        for (int i=0; i<stamp.size(); ++i) {
            if (target[i + idx] != '?' && target[i + idx] != stamp[i]) {
                return false;
            }
        }
        return true;
    }
};
// Time : O(t * (t - s))
// Space : O(t * (t - s))