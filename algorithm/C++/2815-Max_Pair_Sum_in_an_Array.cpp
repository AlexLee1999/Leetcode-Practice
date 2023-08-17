class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int, vector<int>> myMap;
        int result = -1;
        for (int i=0; i<nums.size(); ++i) {
            int maxDigits = findMaxDigits(nums[i]);
            myMap[maxDigits].push_back(nums[i]);
        }
        for (auto it = myMap.begin(); it != myMap.end(); ++it) {
            result = max(result, findFirstAndSecondLargest(it->second));
        }
        return result;
    }
    int findMaxDigits(int n) {
        int maxDigits = 0;
        while (n > 0) {
            maxDigits = max(maxDigits, n % 10);
            n /= 10;
        }
        return maxDigits;
    }
    int findFirstAndSecondLargest(vector<int>& arr) {
        int first = INT_MIN;
        int second = INT_MIN;
        for (int i=0; i<arr.size(); ++i) {
            if (arr[i] > first) {
                second = first;
                first = arr[i];
            } else if (arr[i] > second) {
                second = arr[i];
            }
        }
        return first + second;
    }
};