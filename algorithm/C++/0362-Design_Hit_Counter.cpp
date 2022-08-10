class HitCounter {
public:
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        myQueue.push(timestamp);
    }
    
    int getHits(int timestamp) {
        while (!myQueue.empty() && myQueue.front() <= timestamp - 300) {
            myQueue.pop();
        }
        return myQueue.size();
    }
private:
    queue<int> myQueue;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */