class MRUQueue {
public:
    MRUQueue(int n) {
        int len = (int)sqrt(n) + 1;
        mruQueue = vector<vector<int>> (len, vector<int>());
        for (int i=1; i<=n; ++i) {
            mruQueue[(i - 1)/len].push_back(i);
        }
    }
    
    int fetch(int k) {
        k --;
        int len = mruQueue.size();
        int idx = k % len;
        int num = mruQueue[k / len][idx];
        mruQueue[len - 1].push_back(num);
        mruQueue[k/len].erase(mruQueue[k/len].begin() + idx);
        for (int i=k/len; i<len - 1; ++i) {
            int front = mruQueue[i + 1][0];
            mruQueue[i + 1].erase(mruQueue[i + 1].begin());
            mruQueue[i].push_back(front);
        }
        return num;
    }
private:
    vector<vector<int>> mruQueue;
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */