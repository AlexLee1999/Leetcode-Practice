class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if (!minHeap.empty() && num >= minHeap.top()) {
            minHeap.push(num);
        } else if (!maxHeap.empty() && num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        balance();
    }
    
    double findMedian() {
        if (minHeap.size() == maxHeap.size() + 1) {
            return (double)minHeap.top();
        } else if (minHeap.size() == maxHeap.size()) {
            return ((double)maxHeap.top() + (double)minHeap.top())/2;
        }
        return 0.0;
        
    }
private:
    priority_queue<int, vector<int>, less<int>> maxHeap;    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    void balance() {
        if (maxHeap.size() == minHeap.size()) {
            return;
        } else if (maxHeap.size() + 1 == minHeap.size()) {
            return;
        } else if (maxHeap.size() + 2 == minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            return;
        } else if (maxHeap.size() == minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            return;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */