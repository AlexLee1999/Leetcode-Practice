class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> table = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> mySet;
        for (int i=0; i<words.size(); ++i) {
            string s = "";
            for (int j=0; j<words[i].size(); ++j) {
                s += table[words[i][j] - 'a'];
            }
            mySet.insert(s);
        }
        return mySet.size();
    }
};
// Time : O(n)
// Space : O(n)