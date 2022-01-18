class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") {
            return 0;
        }
        if (haystack == "" && needle != "" || haystack.size() < needle.size()) {
            return -1;
        }
        if (haystack.size() == needle.size()){
            return (haystack == needle) ? 0 : -1;
        }
        int h_ptr = 0;
        int n_ptr = 0;
        for (int i=0; i<=haystack.size() - needle.size(); ++i) {
            h_ptr = i;
            n_ptr = 0;
            while (n_ptr < needle.size() && haystack[h_ptr] == needle[n_ptr]) {
                h_ptr ++;
                n_ptr ++;
            }
            if (n_ptr == needle.size()) {
                return i;
            }
        }
        return -1;
    }
};