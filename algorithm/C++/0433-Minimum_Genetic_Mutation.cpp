class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> mySet(bank.begin(), bank.end());
        if (mySet.count(end) == 0) {
            return -1;
        }
        queue<string> myQueue;
        myQueue.push(start);
        
        unordered_map<string, bool> visited;
        visited[start] = true;
        vector<char> DNA = {'A', 'C', 'G', 'T'};
        int step = 0;
        while(!myQueue.empty()) {
            int size = myQueue.size();
            for (int k=0; k<size; ++k) {
               string front = myQueue.front();
                myQueue.pop();
                if (front == end) {
                    return step;
                }
                for (int i=0; i<8; ++i) {
                    for (int j=0; j<4; ++j) {
                        string tmp = front.substr(0, i) + DNA[j] + front.substr(i + 1);
                        if (mySet.count(tmp) != 0 && !visited[tmp]) {
                            myQueue.push(tmp);
                            visited[tmp] = true;
                        }
                    }
                } 
            }
            step ++;
        }
        return -1;
    }
};
// Time : O(NL) L = 8
// Space : O(N)