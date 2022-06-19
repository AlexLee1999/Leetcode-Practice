class Solution {
public:
    string defangIPaddr(string address) {
        string s = "";
        for (int i=0; i<address.size(); ++i) {
            if (address[i] == '.') {
                s += "[.]";
            } else {
                s += address[i];
            }
        }
        return s;
    }
};
// Time : O(n)
// Space : O(n)