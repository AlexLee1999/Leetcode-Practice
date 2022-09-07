class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum % 2 == 1) {
            return {};
        }
        vector<long long> ans;
        long long sum = 0;
        long long ptr = 1;
        while (sum + ptr * 2 <= finalSum) {
            sum += ptr * 2;
            ans.push_back(ptr * 2);
            ptr ++;
        }
        ans.back() = ans.back() + (finalSum - sum);
        return ans;
    }
};
// Time : O(sqrtn)
// Space : O(sqrtn)