class Solution {
public:
    int minPartitions(string n) {
        int need_digit=0;
        for(int i=0; i<n.size(); ++i){
            need_digit = max(need_digit, n[i] - '0');
        }
        return need_digit;
    }
};
// Time : O(n)
// Space : O(1)