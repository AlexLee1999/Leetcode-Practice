class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0;
        while (i < s.size()){
            if (i % (2 * k) == 0){
                if (i + k > s.size()) {
                    reverse(s.begin() + i, s.end());
                } else {
                    reverse(s.begin() + i, s.begin() + i + k);
                }
                
            }
            i ++;
        }
        return s;
    }
};
// Time : O(n)
// Space : O(1)