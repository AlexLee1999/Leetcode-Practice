class Solution {
public:
    int calculate_sum(vector<int>& satisfaction, int pos) {
        int sum = 0;
        for (int i=pos; i<satisfaction.size(); ++i) {
            sum += satisfaction[i] * (i - pos + 1);
        }
        return sum;
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int max_sum = 0;
        for (int i=0; i<satisfaction.size(); ++i) {
            max_sum = max(max_sum, calculate_sum(satisfaction, i));
        }
        return max_sum;
    }
};