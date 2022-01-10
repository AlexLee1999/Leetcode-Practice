class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0;
        int high = numbers.size() - 1;
        while (true) {
            if (numbers[low] + numbers[high] > target) {
                high--;
            }
            else if (numbers[low] + numbers[high] < target) {
                low++;
            }
            else {
                break;
            }
        }
        vector<int> res {low + 1, high + 1};
        return res;
    }
};
