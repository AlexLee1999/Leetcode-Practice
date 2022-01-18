class SparseVector {
public:
    SparseVector(vector<int> &nums) {
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] != 0) {
                _myMap[i] = nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int result = 0;
        for (auto it = _myMap.begin(); it != _myMap.end(); ++it) {
            if (vec._myMap.find(it->first) != vec._myMap.end()) {
                result += (it->second * vec._myMap[it->first]);
            }
        }
        return result;
    }
private:
    unordered_map<int, int> _myMap;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);