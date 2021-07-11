class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int j = 0;
        int max_num = 0;
        for(short i = 0; i < s.length(); ++i){
            if(map.find(s[i]) != map.end()){
                j = max(j, map[s[i]] + 1);
            }
            if(max_num < i - j + 1){
                max_num = i - j + 1;
            }
            map[s[i]] = i;
        }
        return max_num;
    }
};
