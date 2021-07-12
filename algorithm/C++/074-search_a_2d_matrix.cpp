class Solution {
public:
    void transform(int& i, int& j, int x, const int& n){
        i = x / n;
        j = x % n;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int high = m*n-1;
        int low = 0;
        int i=0;
        int j=0;
        while (low<=high){
            int mid = (low+high) / 2;
            transform(i, j, mid, n);
            if(matrix[i][j]==target){
                return true;
            }
            else if(matrix[i][j]<target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return false;
    }
};
