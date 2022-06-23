class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        priority_queue<int, vector<int>, less<int>> myHeap;
        
        int cur_time = 0;
        for (int i=0; i<courses.size(); ++i) {
            myHeap.push(courses[i][0]);
            cur_time += courses[i][0];
            while (!myHeap.empty() && cur_time > courses[i][1]) {
                cur_time -= myHeap.top();
                myHeap.pop();
            }
        }
        return myHeap.size();
    }
};
// Time : O(nlogn)
// Space : O(n)