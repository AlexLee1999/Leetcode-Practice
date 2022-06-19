class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s[n-1] == '1') {
            return false;
        }
        int prev = 0;
        vector<int> reach;
        reach.push_back(0);
        for (int i=1; i<n; ++i) {
            if (s[i] == '0') {
                for (int j = reach.size()-1; j >= 0; --j) {
                    if (reach[j] + minJump <= i && reach[j] + maxJump >= i) {
                        reach.push_back(i);
                        break;
                    }
                }
            }
        }
        return reach.back() == n - 1;
    }
};