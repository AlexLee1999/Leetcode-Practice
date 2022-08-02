class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty()) {
            myQueue.push({0, 1});
        }
        if (!v2.empty()) {
            myQueue.push({0, 2});
        }
        arr1 = v1;
        arr2 = v2;
    }

    int next() {
        int q = myQueue.front().second;
        int num = myQueue.front().first;
        myQueue.pop();
        if (q == 1) {
            if (num + 1 < arr1.size()) {
                myQueue.push({num + 1, 1});
            }
            return arr1[num];
        }
        if (q == 2) {
            if (num + 1 < arr2.size()) {
                myQueue.push({num + 1, 2});
            }
            return arr2[num];
        }
        return -1;
    }

    bool hasNext() {
        return !myQueue.empty();
    }
private:
    queue<pair<int, int>> myQueue;
    vector<int> arr1;
    vector<int> arr2;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */