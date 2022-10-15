struct cmp1 {
  bool operator() (pair<int, string>& a, pair<int, string>& b){
      if (a.first == b.first) {
          return a.second > b.second;
      }
      return a.first < b.first;
  }  
};

struct cmp2 {
  bool operator() (pair<int, string>& a, pair<int, string>& b){
      if (a.first == b.first) {
          return a.second < b.second;
      }
      return a.first > b.first;
  }  
};

class SORTracker {
public:
    SORTracker() {

    }
    
    void add(string name, int score) {
        if (myHeap1.empty() && myHeap2.empty()) {
            myHeap1.push({score, name});
        } else if (!myHeap2.empty() && (score > myHeap2.top().first || (score == myHeap2.top().first && name < myHeap2.top().second))) {
            myHeap1.push(myHeap2.top());
            myHeap2.pop();
            myHeap2.push({score, name});
        } else {
            myHeap1.push({score, name});
        }
    }
    
    string get() {
        string ans = myHeap1.top().second;
        myHeap2.push(myHeap1.top());
        myHeap1.pop();
        return ans;
    }
private:
    priority_queue<pair<int, string>, vector<pair<int, string>>, cmp1> myHeap1;
    priority_queue<pair<int, string>, vector<pair<int, string>>, cmp2> myHeap2;
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */