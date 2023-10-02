class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> count;
        for (int i=0; i<nums.size(); ++i) {
            count[nums[i]] ++;
        }
        for (auto it = count.begin(); it != count.end(); ++it) {
            int num = it->first;
            if (it->second == 0) {
                continue;
            }
            while (it->second > 0) {
                for (int i=num; i<num + k; ++i) {
                    if (count[i] == 0) {
                        return false;
                    }
                    count[i] --;
                }
            }
        }
        return true;
    }
};