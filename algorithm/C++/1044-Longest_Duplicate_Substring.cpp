class Solution {
public:
    string longestDupSubstring(string s) {
        int left = 1;
        int right = s.size();
        vector<int> pow(s.size(), 1);
        int mod = 1e7 + 7;
        for (int i=1; i<s.size(); ++i) {
            pow[i] = (pow[i - 1] * 26) % mod;
        }
        string ans = "";
        while (left <= right) {
            int mid = left + (right - left) / 2;
            string res = search(s, mid, pow, mod);
            if (res != "") {
                ans = res;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
        
    }
    string search(string& s, int len, vector<int>& pow, int mod) {
        unordered_map<int, vector<int>> myMap;
        int cur_hash = 0;
        for (int i=0; i<len; ++i) {
            cur_hash = (cur_hash * 26 + (s[i] - 'a')) % mod;
        }
        myMap[cur_hash] = {0};
        for (int i=len; i<s.size(); ++i) {
            cur_hash = (cur_hash - pow[len - 1] * (s[i - len] - 'a') % mod + mod) % mod;
            cur_hash = (cur_hash * 26 + (s[i] - 'a')) % mod;
            if (myMap.find(cur_hash) != myMap.end()) {
                for (int j=0; j<myMap[cur_hash].size(); ++j) {
                    string substr = s.substr(myMap[cur_hash][j], len);
                    if (substr == s.substr(i - len + 1, len)) {
                        return substr;
                    }
                }
            }
            myMap[cur_hash].push_back(i - len + 1);
        }
        return "";
    }
};
// Time : O(nlogn)
// Space : O(n)