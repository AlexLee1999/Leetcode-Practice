class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans (rains.size(), -1);
        unordered_map<int, int> lastDay;
        set<int> dryDays;
        for (int i=0; i<rains.size(); ++i) {
            if (rains[i] > 0) {
                if (lastDay.count(rains[i])) {
                    auto it = dryDays.upper_bound(lastDay[rains[i]]);
                    if (it == dryDays.end()) {
                        return {};
                    }
                    ans[*it] = rains[i];
                    dryDays.erase(*it);
                }
                lastDay[rains[i]] = i;
            } else {
                dryDays.insert(i);
                ans[i] = 1; // Default: dry lake 1 if there are no lake to dry
            }
        }
        return ans;
    }
};
// Time : O(nlogn)
// Space : O(n)