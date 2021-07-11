class Solution {
public:
    void count_sub(int left, int right, int&count, string& s){
        while(left>=0 && right < s.size() && s[left]==s[right]){
            count ++;
            left--;
            right++;
        }
    }
    int countSubstrings(string s) {
        int count=0;
        for (int i=0; i<s.size(); ++i){
            count_sub(i, i, count, s);//for odd cases;
            count_sub(i, i+1, count, s);//for even cases;
        }
        return count;
    }
};
