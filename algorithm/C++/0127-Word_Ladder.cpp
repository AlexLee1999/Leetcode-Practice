class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> mySet (wordList.begin(), wordList.end());
        unordered_set<string> visited;
        queue<string> myQueue;
        myQueue.push(beginWord);
        int step = 1;
        while (!myQueue.empty()) {
            int size = myQueue.size();
            for (int k=0; k<size; ++k) {
                string front = myQueue.front();
                myQueue.pop();
                for (int i=0; i<front.size(); ++i) {
                    for (char j='a'; j<='z'; ++j) {
                        string tmp = front.substr(0, i) + j + front.substr(i + 1);
                        if (mySet.count(tmp) && !visited.count(tmp)) {
                            if (tmp == endWord) {
                                return step + 1;
                            }
                            visited.insert(tmp);
                            myQueue.push(tmp);
                        }
                    }
                }
            }
            step ++;
        }
        return 0;
    }
};
// Time : O(N*26^l) l is the length of the word
// Space : O(N)