class Solution {
public:
    int maxLength(vector<string>& arr) { 
        vector<string> cur;
        int max_len = 0;
        backtrack(arr, cur, max_len, 0);
        return max_len;
    }
        
    void backtrack(vector<string>& arr, vector<string>& cur, int& max_len, int idx) {
        if (idx == arr.size()) {
            vector<int> table(26, 0);
            int cur_len = 0;
            for (int i=0; i<cur.size(); ++i) {
                for (int j=0; j<cur[i].size(); ++j) {
                    table[cur[i][j] - 'a'] ++;
                    if (table[cur[i][j] - 'a'] > 1) {
                        return;
                    }
                    cur_len ++;
                }
            }
            max_len = max(cur_len, max_len);
            return;
        }
        cur.push_back(arr[idx]);
        backtrack(arr, cur, max_len, idx + 1);
        cur.pop_back();
        backtrack(arr, cur, max_len, idx + 1);
    }
};
// Time : O(2^n)
// Space : O(2^n)