class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        unordered_set<int> mySet;
        int count = 0;
        long long sum = 0;
        int num = 1;
        while (count < n) {
            if (!mySet.count(target - num)) {
                mySet.insert(num);
                count ++;
                sum += num;
            }
            num ++;
        }
        return sum;
    }
};