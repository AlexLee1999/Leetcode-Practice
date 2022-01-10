class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_set<char> my_set;
        for (int i=0; i<s.size(); ++i) {
            if (my_set.find(s[i]) == my_set.end()) {
               my_set.insert(s[i]); 
            } else {
                my_set.erase(s[i]);
            }
            
        }
        return my_set.size() > 1 ? false:true;
    }
};