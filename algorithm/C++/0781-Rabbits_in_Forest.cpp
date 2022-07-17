class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> myMap;
        int count = 0;
        for (int i=0; i<answers.size(); ++i) {
            myMap[answers[i]] ++;
        }
        for (auto it = myMap.begin(); it != myMap.end(); ++it) {
            count += (it->first + 1) * ceil((double)it->second/((double)it->first + 1));
        }
        return count;
    }
};
// Time : O(n)
// Space : O(n)
/* Idea : if there are n + 1 rabbits say that there are n rabbits, the minimum rabbit is n + 1 */