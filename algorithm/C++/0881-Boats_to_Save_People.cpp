class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0;
        int right = people.size() - 1;
        int ans = 0;
        while (left <= right) {
            if (left == right) {
                ans ++;
                left ++;
                right --;
            } else if (people[left] + people[right] <= limit) {
                ans ++;
                left ++;
                right --;
            } else {
                right --;
                ans ++;
            }
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(1)