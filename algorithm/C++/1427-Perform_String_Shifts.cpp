class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int n = s.size();
        int total_shift = 0;
        for (int i=0; i<shift.size(); ++i) {
            total_shift += (shift[i][0] == 0) ? -1 * shift[i][1] : shift[i][1]; 
        }
        return shiftStr(s, total_shift);
    }
    string shiftStr(string& s, int shift) {
        int n = s.size();
        while (shift < 0) {
            shift += n;
        }
        shift %= n;
        return s.substr(n - shift, shift) + s.substr(0, n - shift);
    }
};
// Time : O(n + k)
// Space : O(k)