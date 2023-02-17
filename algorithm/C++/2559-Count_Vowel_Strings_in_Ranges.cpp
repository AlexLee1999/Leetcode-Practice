class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        int q = queries.size();
        vector<int> arr(n + 1, 0);
        vector<int> ans(q, 0);
        for (int i=0; i<n; ++i) {
            arr[i + 1] = arr[i] + (int)startAndEndWithVowels(words[i]);
        }
        for (int i=0; i<q; ++i) {
            ans[i] = arr[queries[i][1] + 1] - arr[queries[i][0]];
        }
        return ans;
    }
    bool startAndEndWithVowels(const string& s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        if (vowels.count(s[0]) && vowels.count(s.back())) {
            return true;
        }
        return false;
    }
};
// Time : O(n + q)
// Space : O(n)