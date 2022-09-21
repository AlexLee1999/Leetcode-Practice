class Solution {
public:
    int scoreOfStudents(string s, vector<int>& answers) {
        vector<vector<unordered_set<int>>> myMap(s.size(), vector<unordered_set<int>>(s.size()));
        expressions(s, 0, s.size() - 1, myMap);
        stack<int> myStack;
        for (int i=0; i<s.size(); ++i) {
            if ('0' <= s[i] && s[i] <= '9') {
                if (i > 0 && s[i - 1] == '*') {
                    int res = (s[i] - '0') * myStack.top();
                    myStack.pop();
                    myStack.push(res);
                } else {
                    myStack.push(s[i] - '0');
                }
            }
        }
        int correct = 0;
        while (!myStack.empty()) {
            correct += myStack.top();
            myStack.pop();
        }
        int ans = 0;
        for (int i=0; i<answers.size(); ++i) {
            if (answers[i] == correct) {
                ans += 5;
            } else if (myMap[0][s.size() - 1].count(answers[i])) {
                ans += 2;
            }
        }
        return ans;
    }
    void expressions(string& s, int l, int r, vector<vector<unordered_set<int>>>& myMap) {
        if (!myMap[l][r].empty()) {
            return;
        }
        unordered_set<int> ans;
        for (int i=l; i<=r; ++i) {
            if (s[i] == '+' || s[i] == '*') {
                expressions(s, l, i - 1, myMap);
                expressions(s, i + 1, r, myMap);
                for (auto it1= myMap[l][i-1].begin(); it1 != myMap[l][i-1].end(); ++it1) {
                    for (auto it2=myMap[i+1][r].begin(); it2!=myMap[i+1][r].end(); ++it2) {
                        int tmp = 0;
                        if (s[i] == '+') {
                            tmp = *it1 + *it2;
                        } else {
                            tmp = *it1 * *it2;
                        }
                        if (tmp <= 1000) {
                            ans.insert(tmp);
                        }
                    }
                }
            }
        }
        if (ans.size() == 0) {
            ans.insert(s[l] - '0');
        }
        myMap[l][r] = ans;
        return;
    }
};
// Time : O(2^n + m)
// Space : O(2^n + m)