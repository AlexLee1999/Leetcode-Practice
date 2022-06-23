class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int high = m * n - 1;
        int low = 0;
        int i=0; 
        int j=0;
        while (low <= high){
            int mid = low + (high - low) / 2;
            i = mid / n;
            j = mid % n;
            
            if (matrix[i][j] == target){
                return true;
            } else if (matrix[i][j] < target) {
                low = mid + 1;
            } else{
                high = mid - 1;
            }
        }
        return false;
    }
};
// Time : O(log(mn))
// Space : O(1)
