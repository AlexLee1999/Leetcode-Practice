class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec) {
        i = 0;
        j = 0;
        arr = vec;
        adjust();
    }
    
    void adjust () {
        while (i < arr.size() && j == arr[i].size()) {
            j = 0;
            i ++;
        }
    }
    
    int next() {
        int tmp = arr[i][j];
        j ++;
        adjust();
        return tmp;
    }
    
    bool hasNext() {
        if (i >= arr.size()) {
            return false;
        }
        if (i == arr.size() - 1 && j == arr[i].size()) {
            return false;
        }
        return true;
    }
private:
    int i;
    int j;
    vector<vector<int>> arr;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */