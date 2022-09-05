class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> banned_set(banned.begin(), banned.end());
        for (int i=0; i<paragraph.size(); ++i) {
            if ('a' <= paragraph[i] && paragraph[i] <= 'z') {
                continue;
            } else if ('A' <= paragraph[i] && paragraph[i] <= 'Z') {
                paragraph[i] += 32;
            } else if (paragraph[i] == ' ') {
                continue;
            } else {
                paragraph[i] = ' ';
            }
        }
		// preprocess the string
		// 1. change all char to lower alphabet
		// 2. change all non-alphabet to space
		
        vector<string> arr;
        int prev = 0;
        for (int i=0; i<=paragraph.size(); ++i) {
            if (i == paragraph.size() || paragraph[i] == ' ') {
                if (prev < i) {
                    arr.push_back(paragraph.substr(prev, i - prev));
                    prev = i + 1;
                } else {
                    prev++;
					// handle multiple white space 
                }
            } else {
                continue;
            }
        }
		// tokenize the string with white space
        unordered_map<string, int> myMap;
        int max_num = 0;
        string max_str = "";
        for (int i=0; i<arr.size(); ++i) {
            if (banned_set.count(arr[i])) {
                continue;
            }
            myMap[arr[i]] ++;
            if (myMap[arr[i]] > max_num) {
                max_str = arr[i];
                max_num = myMap[arr[i]];
            }
        }
        return max_str;
    }
};
// Time : O(n + m)
// Space : O(n + m) m is the banned word list