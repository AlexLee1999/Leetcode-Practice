class MyHashMap {
public:
    MyHashMap() {
        arr = vector<vector<pair<int, int>>>(4391, vector<pair<int, int>>());
    }
    
    void put(int key, int value) {
        int arr_key = key % 4391;
        bool found = false;
        for (int i=0; i<arr[arr_key].size(); ++i) {
            if (arr[arr_key][i].first == key) {
                arr[arr_key][i].second = value;
                found = true;
            }
        }
        if (!found) {
            arr[arr_key].push_back({key, value});
        }
    }
    
    int get(int key) {
        int arr_key = key % 4391;
        if (arr[arr_key].empty()) {
            return -1;
        }
        for (int i=0; i<arr[arr_key].size(); ++i) {
            if (arr[arr_key][i].first == key) {
                return arr[arr_key][i].second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int arr_key = key % 4391;
        if (arr[arr_key].empty()) {
            return;
        }
        for (int i=0; i<arr[arr_key].size(); ++i) {
            if (arr[arr_key][i].first == key) {
                arr[arr_key].erase(arr[arr_key].begin() + i);
                return;
            }
        }
    }
private:
    vector<vector<pair<int, int>>> arr;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */