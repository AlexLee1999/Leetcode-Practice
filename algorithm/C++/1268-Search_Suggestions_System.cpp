class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        int n = products.size();
        string prefix = "";
        int start = 0;
        vector<vector<string>> ans(searchWord.size(), vector<string>());
        for (int i=0; i<searchWord.size(); ++i) {
            prefix += searchWord[i];
            int lower = lower_bound(products.begin() + start, products.end(), prefix) - products.begin();
            for (int j=lower; j<min(lower + 3, n); ++j) {
                if (products[j].substr(0, i+1) == prefix) {
                    ans[i].push_back(products[j]);
                }
            }
            start = lower;
        }
        return ans;
    }
};
// Time : O(m * nlogn) Sorting with string with max char m
// Space : O(1)~O(n)