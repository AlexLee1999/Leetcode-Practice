class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        unordered_map<string, unordered_set<string>> myMap;
        if (sentence1.size() != sentence2.size()) {
            return false;
        }
        for (int i=0; i<similarPairs.size(); ++i) {
            myMap[similarPairs[i][0]].insert(similarPairs[i][1]);
            myMap[similarPairs[i][1]].insert(similarPairs[i][0]);
        }
        for (int i=0; i<sentence1.size(); ++i) {
            if (sentence1[i] == sentence2[i] || search(sentence1[i], sentence2[i], myMap) || search(sentence2[i], sentence1[i], myMap)) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
    bool search(string& a, string& b, unordered_map<string, unordered_set<string>>& myMap) {
        stack<string> myStack;
        unordered_map<string, bool> visited;
        myStack.push(a);
        visited[a] = true;
        while(!myStack.empty()) {
            string front = myStack.top();
            if (front == b) {
                return true;
            }
            myStack.pop();
            for (auto it=myMap[front].begin(); it != myMap[front].end(); ++it) {
                if (!visited[*it]) {
                    visited[*it] = true;
                    myStack.push(*it);
                }
            }
        }
        return false;
    }
};