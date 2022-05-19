class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> myHeap; 
        //pair <int, int> {end, numPassenger}
        int num = trips[0][0];
        myHeap.push({trips[0][2], trips[0][0]});
        for (int i=1; i<trips.size(); ++i) {
            if (num > capacity) {
                return false;
            }
            while (!myHeap.empty()) {
                if (myHeap.top().first <= trips[i][1]) {
                num -= myHeap.top().second;
                myHeap.pop();
                } else {
                    break;
                }
            }
            myHeap.push({trips[i][2], trips[i][0]});
            num += trips[i][0];
        }
        return num <= capacity;
    }
};