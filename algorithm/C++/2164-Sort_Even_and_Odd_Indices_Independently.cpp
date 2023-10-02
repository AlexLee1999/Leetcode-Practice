class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<bool> evenoddArr;
        vector<int> evenArr;
        vector<int> oddArr;
        for (int i=0; i<nums.size(); ++i) {
            bool isOdd = (bool)(i & 1);
            if (!isOdd) {
                evenArr.push_back(nums[i]);
            } else {
                oddArr.push_back(nums[i]);
            }
        }
        sort(evenArr.begin(), evenArr.end());
        sort(oddArr.begin(), oddArr.end(), greater<int>());
        int evenPtr = 0;
        int oddPtr = 0;
        for (int i=0; i<nums.size(); ++i) {
            bool isOdd = (bool)(i & 1);
            if (!isOdd) {
                nums[i] = evenArr[evenPtr ++];
            } else {
                nums[i] = oddArr[oddPtr ++];
            }
        }
        return nums;
    }
};