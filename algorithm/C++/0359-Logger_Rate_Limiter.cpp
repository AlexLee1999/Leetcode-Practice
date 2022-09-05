class Logger {
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (!myMap.count(message)) {
            myMap[message] = timestamp;
            return true;
        }
        if (myMap[message] <= timestamp - 10) {
            myMap[message] = timestamp;
            return true;
        } else {
            return false;
        }
        return false;
    }
private:
    unordered_map<string, int> myMap;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */