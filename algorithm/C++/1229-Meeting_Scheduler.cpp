class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        int ptr1 = 0;
        int ptr2 = 0;
        while (ptr1 < slots1.size() && ptr2 < slots2.size()) {
            int left = max(slots1[ptr1][0], slots2[ptr2][0]);
            int right = min(slots1[ptr1][1], slots2[ptr2][1]);
            
            if (right - left >= duration) {
                return vector<int>{left, left + duration};
            }
            
            if (slots2[ptr2][1] < slots1[ptr1][1]) {
                ptr2 ++;
            } else {
                ptr1 ++;
            }
        }
        return vector<int>{};
    }
};
// Time : O(n1logn1 + n2logn2)
// Space : O(1)