class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string, int> myMap;
        for (int i=0; i<emails.size(); ++i) {
            vector<string> tmp = decomposeEmail(emails[i]);
            string dom = domain(tmp[0]);
            string transformed = dom + '@' + tmp[1];
            myMap[transformed] ++;
        }
        return myMap.size();
        
    }
    vector<string> decomposeEmail(string& s) {
        vector<string> ans;
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '@') {
                ans.push_back(s.substr(0, i));
                ans.push_back(s.substr(i + 1));
                return ans;
            }
        }
        return ans;
    }
    string domain(string s) {
        bool plus = false;
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '.') {
                s[i] = '$';
            } else if (s[i] == '+') {
                plus = true;
                s[i] = '$';
            }
            if (plus) {
                s[i] = '$';
            }
        }
        s.erase(remove(s.begin(), s.end(), '$'), s.end());
        return s;
    }
};
// Time : O(n)
// Space : O(n)