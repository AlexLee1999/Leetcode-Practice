class Solution {
public:
    struct cmp {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b){
            return a.second > b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> myMap;
        for (int i=0; i<nums.size(); ++i) {
            myMap[nums[i]] ++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> myHeap;
        for (auto it = myMap.begin(); it!= myMap.end(); ++it) {
            myHeap.push({it->first, it->second});
            if (myHeap.size() > k) {
                myHeap.pop();
            }
        }
        vector<int> ans;
        for (int i=0; i<k; ++i) {
            ans.push_back(myHeap.top().first);
            myHeap.pop();
        }
        return ans;
    }
};
// Time : O(nlogn)
// Space : O(n)