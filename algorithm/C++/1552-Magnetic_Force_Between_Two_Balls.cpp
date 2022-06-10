class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int left = 1;
        int right = position[position.size() - 1] - position[0];
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(position, m, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
        
        
    }
    bool isPossible(vector<int>& position, int m, int force) {
        int prev = position[0];
        int count = 1;
        for (int i=1; i<position.size(); ++i) {
            if (position[i] - prev >= force) {
                prev = position[i];
                count ++;
            }
            if (count == m) {
                return true;
            }
        }
        return false;
        
    }
};
// Time : O(NlogN)
// Space : O(1)