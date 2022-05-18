class Solution {
public:
    struct cmp {
        bool operator () (const pair<int, string>& a, const pair<int, string>& b){
            if (a.first != b.first) {
                return a.first < b.first;
            } else {
                return a.second > b.second;
            }
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> myMap;
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> myHeap;
        for (int i=0; i<words.size(); ++i) {
            myMap[words[i]] ++;
        }
        for (auto it = myMap.begin(); it != myMap.end(); ++it) {
            myHeap.push({it->second, it->first});
        }
        vector<string> ans;
        for (int i=0; i<k; ++i) {
            pair<int, string> tmp = myHeap.top();
            ans.push_back(tmp.second);
            myHeap.pop();
        }
        
        return ans;
    }
};