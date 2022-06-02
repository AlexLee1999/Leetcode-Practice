class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        for (int i=0; i<chalk.size()-1; ++i) {
            if (chalk[i] > k) {
                return i;
            }
            chalk[i+1] += chalk[i];
            
        }
        k %= chalk[chalk.size()-1];
        int left = 0;
        int right = chalk.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (chalk[mid] > k) {
                right = mid - 1;
            } else if (chalk[mid] <= k) {
                left = mid + 1;
            }
        }
        return left;
    }
};