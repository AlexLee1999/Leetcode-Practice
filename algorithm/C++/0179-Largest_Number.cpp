class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> string_nums(nums.size(), "");
        for (int i=0; i<nums.size(); ++i) {
            string_nums[i] = to_string(nums[i]);
        }
        sort(string_nums.begin(), string_nums.end(), [](const string& a, const string& b){
            return (a + b) > (b + a);
        });
        string s = "";
        bool first = true;
        for (int i=0; i<string_nums.size(); ++i) {
            if (first && string_nums[i] == "0"){
                return "0";
            } else if (first && string_nums[i] != "0") {
                first = false;
            }
            s += string_nums[i];
        }
        return s;
    }
};