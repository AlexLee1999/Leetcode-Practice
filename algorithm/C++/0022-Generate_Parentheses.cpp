class Solution {
public:
    void recursiveGen(string s, vector<string>& res, int open, int close, int tot){
        if (close == tot) {
            res.push_back(s);
        }
        if (close<open) { //if close < open, can add ')'
            string ret_s = s + ")";
            recursiveGen(ret_s, res, open, close + 1, tot);
        }
        if (open<tot) { //if open < total, can add '('
            string ret_s = s+ "(";
            recursiveGen(ret_s, res, open + 1, close, tot);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        recursiveGen("", res, 0, 0, n);
        return res;
    }
};
// Time : O(2^(2n))
// Space : O(n)