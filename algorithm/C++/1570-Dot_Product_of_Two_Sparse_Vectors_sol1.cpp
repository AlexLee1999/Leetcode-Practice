class SparseVector {
public:
    
    SparseVector(vector<int> &nums) {
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] != 0) {
                myMap[i] = nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int result = 0;
        for (auto it = myMap.begin(); it != myMap.end(); ++it) {
            if (vec.myMap.find(it->first) != vec.myMap.end()) {
                result += (it->second * vec.myMap[it->first]);
            }
        }
        return result;
    }
private:
    unordered_map<int, int> myMap;
};
// The hashing solution is inefficient while in large vector (resize & rehash)

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);