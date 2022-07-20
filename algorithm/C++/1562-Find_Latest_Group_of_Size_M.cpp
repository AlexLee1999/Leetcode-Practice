class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        vector<int> groupSize(n + 2);
        vector<int> count(n + 1);
        int ans = -1;
        for (int i=0; i<n; ++i) {
            int left = groupSize[arr[i] - 1];
            int right = groupSize[arr[i] + 1];
            groupSize[arr[i] + right] = left + right + 1;
            groupSize[arr[i] - left] = left + right + 1;
            count[left] --;
            count[right] --;
            count[left + right + 1] ++;
            if (count[m] > 0) {
                ans = i + 1;
            }
        }
        return ans;
    }
};
// Time : O(n)
// Space : O(n)
/* 
Adding "1" at some index i may do one of the following :

If values at indices i-1 and i+1 are both 0's it will create a new group of length 1.
If any one of the values at indices i-1 and i+1 is zero and one non zero then it will increase the non zero group length by 1.
If both values at indices i-1 and i+1 are non zeroes then it will remove two groups of lenghts left and right and form a new group of length ( left length + right length + 1).
As all the values given are 1 indexed in this question we can club 1 and 2 situations above as third situation by considering lengths as all zeroes initially.
Let N be the array size.
We will maintain an array of length N+2 where it denotes the length of the group at the group ends (As at every step we add 1 at an unique index , it's not necessary to update lengths for every group index only updating at the ends will do the work).
For every index in the array arr consider left = length of left group and right = length of right group update values of length at indices arr[i] - left and arr[i] - right as left + right + 1.
*/