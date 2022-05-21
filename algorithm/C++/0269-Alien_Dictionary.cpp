class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, int> indegree;
        unordered_map<char, vector<char>> edge;
        for (int i=0; i<words.size(); ++i) {
            for (int j=0; j<words[i].size(); ++j) {
                indegree[words[i][j]] = 0;
                edge[words[i][j]] = vector<char>();
            }
        }
        for (int i=0; i<words.size()-1; ++i) {
            string word1 = words[i];
            string word2 = words[i+1];
            for (int j=0; j<min(word1.size(), word2.size()); ++j) {
                if (word1[j] != word2[j]) {
                    edge[word1[j]].push_back(word2[j]);
                    indegree[word2[j]] ++;
                    break;
                }
                if (j == min(word1.size(), word2.size()) - 1) {
                    if ((j + 1) < word1.size() && (j + 1) == word2.size()) {
                        return "";
                    }
                }
            }
        }
        queue<char> myQueue;
        for (auto it = indegree.begin(); it != indegree.end(); ++it) {
            if (it->second == 0) {
                myQueue.push(it->first);
            }
        }
        string s = "";
        while (!myQueue.empty()) {
            char ch = myQueue.front();
            myQueue.pop();
            s += ch;
            for (int i=0; i<edge[ch].size(); ++i) {
                indegree[edge[ch][i]] --;
                if (indegree[edge[ch][i]] == 0) {
                    myQueue.push(edge[ch][i]);
                }
            }
        }
        if (s.size() != indegree.size()) {
            return "";
        }
        return s;
    }
};