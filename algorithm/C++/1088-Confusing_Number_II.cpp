class Solution {
public:
    int confusingNumberII(int n) {
        int ans = 0;
        vector<int> arr = {0, 1, 6, 8, 9};
        for (int i=1; i<arr.size(); ++i) {
            dfs(arr[i], n, ans, arr);
        }
        
        return ans;
    }
    void dfs(long i, int n, int& ans, vector<int>& arr) {
        if (i > n) {
            return;
        }
        if (!equalityPartition(i)) {
            ans ++;
        }
        
        i *= 10;
        for (int j=0; j<arr.size(); ++j) {
            dfs(i + arr[j], n, ans, arr);
        }
    }
    
    bool equalityPartition(int n) {
        string s = to_string(n);
        int left = 0;
        int right = s.size() - 1;
        while (left <= right) {
            if ((s[left] == '6' && s[right] == '9') || (s[left] == '9' && s[right] == '6') || (s[left] == '1' && s[right] == '1') || (s[left] == '0' && s[right] == '0') || (s[left] == '8' && s[right] == '8')) {
                left ++;
                right --;
            } else {
                return false;
            }
        }
        return true;
    }
};