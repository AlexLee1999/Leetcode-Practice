class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_set<int> mySet;
        int count = 0;
        int sum = 0;
        int num = 1;
        while (count < n) {
            if (!mySet.count(k - num)) {
                mySet.insert(num);
                count ++;
                sum += num;
            }
            num ++;
        }
        return sum;
    }
};