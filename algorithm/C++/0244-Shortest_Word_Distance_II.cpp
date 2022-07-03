class WordDistance {
public:
    WordDistance(vector<string>& wordsDict) {
        for(int i=0; i<wordsDict.size(); ++i) {
            myMap[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int min_dis = INT_MAX;
        int word1_ptr = 0;
        int word2_ptr = 0;
        while (word1_ptr < myMap[word1].size() && word2_ptr < myMap[word2].size()) {
            min_dis = min(min_dis, abs(myMap[word1][word1_ptr] - myMap[word2][word2_ptr]));
            if (myMap[word1][word1_ptr] > myMap[word2][word2_ptr]) {
                word2_ptr ++;
            } else {
                word1_ptr ++;
            }
        }
        return min_dis;
    }
private:
    unordered_map<string, vector<int>> myMap;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
// Time : O(N)
// Space : O(N)