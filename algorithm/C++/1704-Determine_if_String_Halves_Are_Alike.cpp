class Solution {
public:
    bool halvesAreAlike(string s) {
        int left = 0;
        int right = s.size() - 1;
        int left_count = 0;
        int right_count = 0;
        unordered_set<char> mySet = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        while(left < right) {
            if (mySet.count(s[left])) {
                left_count ++;
            }
            if (mySet.count(s[right])) {
                right_count ++;
            }
            right --;
            left ++;
        }
        return left_count == right_count;

    }
};
// Time : O(n)
// Space : O(1)