class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty()) {
            return 0;
        }
        sort(begin(citations), end(citations), greater<>());
        int i = 1;
        for (; i <= citations.size(); i++) {
            if (citations[i - 1] < i){
                break;
            }
        }
        return i-1;
    }
};