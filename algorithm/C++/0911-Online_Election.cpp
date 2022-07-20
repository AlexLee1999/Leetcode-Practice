class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int winner = persons[0];
        timeMap[times[0]] = winner;
        int maxVote = 1;
        countMap[persons[0]] = 1;
        for (int i=1; i<times.size(); ++i) {
            countMap[persons[i]] ++;
            if (countMap[persons[i]] >= maxVote) {
                maxVote = countMap[persons[i]];
                winner = persons[i];
            }
            timeMap[times[i]] = winner;
        }
    }
    
    int q(int t) {
        auto it = timeMap.upper_bound(t);
        it --;
        return it->second;
    }

private:
    map<int, int> timeMap;
    unordered_map<int, int> countMap;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
/* Idea : calculate the winner of every time, and use binary search to find the winner at time <= t. */