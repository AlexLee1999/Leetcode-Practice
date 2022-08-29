class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int prev = -1;
        int max_len = 0;
        int len;
        for (int i=0; i<n; ++i) {
            if (seats[i] == 0) { //if not seated
                continue;
            }
            else {
                if (prev == -1) { //first seated seat
                    len = i;
                    max_len = max(len, max_len);
                }
                else {
                    len = (i - prev) / 2; //m, n seated, max distance = (m-n)/2 
                    max_len = max(len, max_len);
                }
                prev = i;
            }
        }
        len = n - prev - 1; //last seated seat
        max_len = max(len, max_len);
        return max_len;
    }
};
// Time : O(n)
// Space : O(1)