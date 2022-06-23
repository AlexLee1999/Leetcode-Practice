class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> edge(n, vector<pair<int, int>>());
        for (int i=0; i<flights.size(); ++i) {
            edge[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        queue<pair<int, int>> myQueue;
        vector<int> distance(n, INT_MAX); // Use Distance to prevent unnecessary search
        distance[src] = 0;
        myQueue.push({src, 0});
        int prize = INT_MAX;
        k += 2;
        while (!myQueue.empty() && k > 0) {
            int size = myQueue.size();
            for (int i=0; i<size; ++i) {
                pair<int, int> front = myQueue.front();
                if (front.first == dst) {
                    prize = min(prize, front.second);
                }
                myQueue.pop();
                for (int j=0; j<edge[front.first].size(); ++j) {
                    if (front.second + edge[front.first][j].second < distance[edge[front.first][j].first]) {
                        myQueue.push({edge[front.first][j].first, front.second + edge[front.first][j].second});
                        distance[edge[front.first][j].first] = front.second + edge[front.first][j].second;
                    }
                }
            }
            k --; 
        }
        return prize == INT_MAX ? -1 : prize;
    }
};
// 