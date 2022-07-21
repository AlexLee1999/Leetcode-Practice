class Solution {
public:
    int shortestWay(string source, string target) {
        unordered_set<char> mySet;
        for (int i=0; i<source.size(); ++i) {
            mySet.insert(source[i]);
        }
        int ptr = 0;
        int ans = 1;
        int i = 0;
        while(i < target.size()) {
            if (ptr == source.size()) {
                ptr = 0;
                ans ++;
            }
            if (mySet.count(target[i]) == 0) {
                return -1;
            }
            if (source[ptr] == target[i]) {
                ptr ++;
                i ++;
            } else {
                ptr ++;
            }
        }
        return ans;
    }
};
// Time : O(m)
// Space : O(n)