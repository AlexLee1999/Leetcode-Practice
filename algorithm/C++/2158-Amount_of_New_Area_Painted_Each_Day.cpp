class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        map<int, int> bound;
        vector<int> ans(paint.size(), 0);
        for (int i=0; i<paint.size(); ++i) {
            int start = paint[i][0];
            int end = paint[i][1];
            int cur_len = end - start;
            auto it = bound.upper_bound(start);
            if (it != bound.begin() && prev(it)->second >= start) {
                it --;
            }
            while (it != bound.end() && it->first <= end) {
                int overlapped = (min(it->second, end) - max(it->first, start));
                cur_len -= overlapped;
                start = min(start, it->first);
                end = max(end, it->second);
                auto tmp = it;
                it ++;
                bound.erase(tmp);
            }
            bound[start] = end;
            ans[i] = cur_len;
        }
        return ans;
    }
};
// Time : O(n^2)
// Space : O(n)