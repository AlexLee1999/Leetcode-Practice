class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> degree(n + 1, 0);
        unordered_map<int, int> edge;
        for (int i=0; i<edges.size(); ++i) {
            degree[edges[i][0]] ++;
            degree[edges[i][1]] ++;
            edge[encode(edges[i][0], edges[i][1])] ++;
        }
        vector<int> sorted_degree = degree;
        sort(sorted_degree.begin(), sorted_degree.end());
        vector<int> ans(queries.size(), 0);
        for (int j=0; j<queries.size(); ++j) {
            int count = 0;
            for (int i=1; i<=n; ++i) {
                int left = i + 1;
                int right = n;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (sorted_degree[i] + sorted_degree[mid] > queries[j]) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
                if (left <= n) {
                    count += (n - left + 1);
                }
            }
            for (auto it = edge.begin(); it != edge.end(); ++it) {
                vector<int> nodes = decode(it->first);
                if (degree[nodes[0]] + degree[nodes[1]] > queries[j] && degree[nodes[0]] + degree[nodes[1]] - it->second <= queries[j]) {
                    count --;
                }
            }
            ans[j] = count;
        }
        return ans;
        
    }
    int encode(int a, int b) {
        if (a > b) {
            return a << 16 | b;
        }
        return b << 16 | a;
    }
    vector<int> decode(int a) {
        return {a >> 16, a & 0xFFFF};
    }
};
// Time : O(e + vlogv + qnlogn + qe)
// Space : O(e + v)