class DSU {
public: 
    DSU (int n) {
        num_count = 0;
        parent = vector<int> (n, 0);
        rank = vector<int> (n, 0);
    }
    
    int getNum() {
        return num_count;
    }
    
    void insert(int x) {
        if (!set.count(x)) {
            parent[x] = x;
            num_count++;
            set.insert(x);
        }
    }
    
    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool join(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty) {
            return false;
        } else {
            num_count --;
            if (rank[rootx] < rank[rooty]) {
                parent[rootx] = rooty;
            } else if (rank[rootx] > rank[rooty]) {
                parent[rooty] = rootx;
            } else {
                parent[rootx] = rooty;
                rank[rootx] ++;
            }
        }
        return true;
    }
private:
    vector<int> parent;
    vector<int> rank;
    unordered_set<int> set;
    int num_count;
};
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        DSU* mySet = new DSU(m * n);
        vector<vector<int>> current = vector<vector<int>>(m, vector<int>(n, 0));
        vector<int> res;
        for (int i=0; i<positions.size(); ++i) {
            mySet->insert(changeIdx(m, positions[i][0], positions[i][1]));
            for (int j=0; j<4; ++j) {
                int x = positions[i][0] + dirs[j][0];
                int y = positions[i][1] + dirs[j][1];
                if (x >= 0 && y >= 0 && x < m && y < n && current[x][y] == 1) {
                    mySet->join(changeIdx(m, positions[i][0], positions[i][1]), changeIdx(m, x, y));
                }
            }
            current[positions[i][0]][positions[i][1]] = 1;
            res.push_back(mySet->getNum());
        }
        return res;
    }
    int changeIdx(int m, int x, int y) {
        return m * y + x;
    }
};
// Time : O(L)
// Space : O(mn)