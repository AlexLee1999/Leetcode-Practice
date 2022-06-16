class Solution {
public:
    double average(vector<int>& salary) {
        int max_num = salary[0] > salary[1] ? salary[0] : salary[1];
        int min_num = salary[0] < salary[1] ? salary[0] : salary[1];
        int cur_sum = 0;
        for (int i=2; i<salary.size(); ++i) {
            if (salary[i] < max_num && salary[i] > min_num) {
                cur_sum += salary[i];
            } else if (salary[i] > max_num) {
                cur_sum += max_num;
                max_num = salary[i];
            } else if (salary[i] < min_num) {
                cur_sum += min_num;
                min_num = salary[i];
            }
        }
        return (double)cur_sum / (double)(salary.size() - 2);
    }
};
// Time : O(n)
// Space : O(1)