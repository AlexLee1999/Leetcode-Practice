class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int right = 0;
        int n = fruits.size();
        unordered_map<int, int> myMap;
        int max_len = 0;
        for (right = 0; right<n; ++right) {
            myMap[fruits[right]] ++;
            while (myMap.size() > 2) {
                myMap[fruits[left]] --;
                if (myMap[fruits[left]] == 0) {
                    myMap.erase(fruits[left]);
                }
                left ++;
            }
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};
// Time : O(n)
// Space : O(n)