class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        set<vector<int>> QueenSet(queens.begin(), queens.end());
        vector<vector<int>> ans;
        int r = king[0];
        int c = king[1];
        int ptr_r = r;
        int ptr_c = c;
        while (ptr_r < 8) {
            if (QueenSet.count({ptr_r, ptr_c})) {
                ans.push_back({ptr_r, ptr_c});
                break;
            }
            ptr_r ++;
        }
        ptr_r = r;
        ptr_c = c;
        while (ptr_c < 8) {
            if (QueenSet.count({ptr_r, ptr_c})) {
                ans.push_back({ptr_r, ptr_c});
                break;
            }
            ptr_c ++;
        }
        ptr_r = r;
        ptr_c = c;
        while (ptr_r >= 0) {
            if (QueenSet.count({ptr_r, ptr_c})) {
                ans.push_back({ptr_r, ptr_c});
                break;
            }
            ptr_r --;
        }
        ptr_r = r;
        ptr_c = c;
        while (ptr_c >= 0) {
            if (QueenSet.count({ptr_r, ptr_c})) {
                ans.push_back({ptr_r, ptr_c});
                break;
            }
            ptr_c --;
        }
        ptr_r = r;
        ptr_c = c;
        while (ptr_r < 8 && ptr_c < 8) {
            if (QueenSet.count({ptr_r, ptr_c})) {
                ans.push_back({ptr_r, ptr_c});
                break;
            }
            ptr_r ++;
            ptr_c ++;
        }
        ptr_r = r;
        ptr_c = c;
        while (ptr_r >= 0 && ptr_c >= 0) {
            if (QueenSet.count({ptr_r, ptr_c})) {
                ans.push_back({ptr_r, ptr_c});
                break;
            }
            ptr_r --;
            ptr_c --;
        }
        ptr_r = r;
        ptr_c = c;
        while (ptr_r < 8 && ptr_c >= 0) {
            if (QueenSet.count({ptr_r, ptr_c})) {
                ans.push_back({ptr_r, ptr_c});
                break;
            }
            ptr_r ++;
            ptr_c --;
        }
        ptr_r = r;
        ptr_c = c;
        while (ptr_r >= 0 && ptr_c < 8) {
            if (QueenSet.count({ptr_r, ptr_c})) {
                ans.push_back({ptr_r, ptr_c});
                break;
            }
            ptr_r --;
            ptr_c ++;
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(q)