class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int, char>, vector<pair<int, char>>, less<pair<int, char>>> myHeap;
        unordered_map<char, int> myMap;
        for (int i=0; i<s.size(); ++i) {
            myMap[s[i]] ++;
        }
        for (auto it = myMap.begin(); it != myMap.end(); ++it) {
            myHeap.push({it->second, it->first});
        }
        string ans = "";
        while(!myHeap.empty()) {
            pair<int, char> tmp = myHeap.top();
            for (int i=0; i<tmp.first; ++i) {
                ans += tmp.second;
            }
            myHeap.pop();
        }
        return ans;
    }
};