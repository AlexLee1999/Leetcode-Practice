class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        myMap[key][-timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = myMap[key].lower_bound(-timestamp);
        if (it == myMap[key].end()) {
            return "";
        }
        return it->second;
    }
private:
    unordered_map<string, map<int, string>> myMap;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// Set : O(logn)
// Get : O(logn)