class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if (n <= 1) {
            return "";
        }
        //first half of the string, 
        //if the string size is odd, won't check the middle char
        for (int i=0; i<n/2; ++i) { 
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[n-1] = 'b';
        return palindrome;
    }
};