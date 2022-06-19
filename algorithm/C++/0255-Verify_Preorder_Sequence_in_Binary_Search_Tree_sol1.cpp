class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        return dfs(preorder, 0, preorder.size()-1, INT_MIN, INT_MAX);
    }
    bool dfs(vector<int>& preorder, int start, int end, int low, int high) {
        if (start > end) {
            return true;
        }
        int val = preorder[start];
        
        if (low >= val || high <= val) {
            return false;
        }
        int i = start + 1;
        for (i = start + 1; i<=end; ++i) {
            if (preorder[i] >= val) {
                break;
            }
        }
        
        return dfs(preorder, start + 1, i - 1, low, val) && dfs(preorder, i, end, val, high);
    }
};
// Time : O(n)
// Space : O(n)