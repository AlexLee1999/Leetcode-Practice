class SparseVector {
public:
    
    SparseVector(vector<int> &nums) {
        arr = nums;
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int ans = 0;
        for (int i=0; i<arr.size(); ++i) {
            ans += (arr[i] * vec.arr[i]);
        }
        return ans;
    }
private:
    vector<int> arr;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);