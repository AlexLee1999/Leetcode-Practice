class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char, int> myMap;
        for (int i=0; i<keyboard.size(); ++i) {
            myMap[keyboard[i]] = i;
        }
        int ans = myMap[word[0]];
        for (int i=1; i<word.size(); ++i) {
            ans += abs(myMap[word[i]] - myMap[word[i - 1]]);
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(1)