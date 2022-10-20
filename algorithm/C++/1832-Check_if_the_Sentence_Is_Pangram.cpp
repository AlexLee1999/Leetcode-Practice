class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> mySet;
        for (int i=0; i<sentence.size(); ++i) {
            mySet.insert(sentence[i]);
        }
        return mySet.size() == 26;
    }
};
// Time : O(n)
// Space : O(1)