class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int i = 0;
        int n = mat.size();
        int sum = 0;
        while(i < n) {
            sum += mat[i][i];
            sum += mat[i][n-i-1];
            i++;
        }
        if((n & 1) == 1){
            sum -= mat[n/2][n/2];
        }
        return sum;
    }
};
// Time : O(nlogn)
// Space : O(1)