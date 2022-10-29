class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        string prev = "";
        vector<string> ans;
        for (int i=0; i<words.size(); ++i) {
            string tmp = words[i];
            sort(tmp.begin(), tmp.end());
            if (prev == tmp) {
                continue;
            }
            prev = tmp;
            ans.push_back(words[i]);
        }
        return ans;
    }
};
// Time : O(nklogk)
// Space : O(n)