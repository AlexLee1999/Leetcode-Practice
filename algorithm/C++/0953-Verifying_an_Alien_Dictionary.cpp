class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> table(26, 0);
        for (int i=0; i<order.size(); ++i) {
            table[order[i] - 'a'] = i;
        }
        
        for (int i=0; i<words.size() - 1; ++i) {
            string first = words[i];
            string second = words[i + 1];
            int j = 0;
            for (j=0; j<min(first.size(), second.size()); ++j) {
                if (first[j] == second[j]) {
                    continue;
                } else if (table[first[j] - 'a'] > table[second[j] - 'a']) {
                    return false;
                } else {
                    break;
                }
                
            }
            if (j == min(first.size(), second.size()) && j < first.size() && j == second.size()) {
                    return false;
            }
        }
        return true;
    }
};
// Time : O(mn)
// Space : O(1)