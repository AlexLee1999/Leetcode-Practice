class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> myMap;
        for (int i=0; i<cpdomains.size(); ++i) {
            int space = -1;
            for (int j=0; j<cpdomains[i].size(); ++j) {
                if (cpdomains[i][j] == ' ') {
                    space = j;
                    break;
                }
            }
            
            int number = stoi(cpdomains[i].substr(0, space));
            string domain = cpdomains[i].substr(space + 1);
            myMap[domain] += number;
            for (int j=0; j<domain.size(); ++j) {
                if (domain[j] == '.') {
                    myMap[domain.substr(j + 1)] += number;
                }
            }
        }
        vector<string> ans;
        for (auto it=myMap.begin(); it != myMap.end(); ++it) {
            string s = "";
            s += to_string(it->second);
            s += ' ';
            s += it->first;
            ans.push_back(s);
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(n)