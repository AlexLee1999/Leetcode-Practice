class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 == str2 + str1) {
            return str1.substr(0, gcd((int)str1.size(), (int)str2.size()));
        }
        return "";
    }
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
};
// Time : O(n)
// Space : O(1)