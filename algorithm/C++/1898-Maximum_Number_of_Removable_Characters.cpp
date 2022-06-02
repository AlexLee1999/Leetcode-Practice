class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int left = 0;
        int right = removable.size();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if(isPossible(s, p, removable, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
    bool isPossible(string s, string p, vector<int>& removable, int index) {
        for (int i=0; i<index; ++i) {
            s[removable[i]] = '$';
        }
        s.erase(std::remove(s.begin(), s.end(), '$'), s.end());
        return isSubsequence(p, s);
    }
    bool isSubsequence(string s, string t) {
        if (t.size() == 0 && s.size() == 0) {
            return true;
        }
        if (t.size() == 0) {
            return false;
        }
        if (s.size() == 0) {
            return true;
        }
        int j = 0;
        for (int i=0; i<t.size(); ++i) {
            if (t[i] == s[j]) {
                j ++;
            }
        }
        return j == s.size();
    }
};