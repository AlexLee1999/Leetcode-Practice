class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i = 0;
        vector<string> cur;
        int cur_width = 0;
        while (i < words.size()) {
            if (cur_width + words[i].size() + cur.size() <= maxWidth) {
                cur.push_back(words[i]);
                cur_width += words[i].size();
                i ++;
            } else {
                if (cur.size() > 1) {
                    ans.push_back(jointText(cur, maxWidth, cur_width));
                    cur.clear();
                    cur_width = 0;
                } else {
                    ans.push_back(jointText_left(cur, maxWidth, cur_width));
                    cur.clear();
                    cur_width = 0;
                }
            }
        }
        ans.push_back(jointText_left(cur, maxWidth, cur_width));
        return ans;
    }
    string jointText(vector<string>& cur, int maxWidth, int cur_width) {
        int space = maxWidth - cur_width;
        int avg_space = space / (cur.size() - 1);
        int extra_space = space - (avg_space * (cur.size() - 1));
        string s = "";
        for (int i=0; i<cur.size()-1; ++i) {
            s += cur[i];
            s += genSpace(avg_space);
            if (extra_space > 0) {
                s += genSpace(1);
                extra_space --;
            }
        }
        s += cur.back();
        return s;
    }
    string jointText_left(vector<string>& cur, int maxWidth, int cur_width) {
        string s = "";
        for (int i=0; i<cur.size() - 1; ++i) {
            s += cur[i];
            s += " ";
        }
        s += cur.back();
        s += genSpace(maxWidth - s.size());
        return s;
    }
    string genSpace(int num) {
        string s = "";
        for (int i=0; i<num; ++i) {
            s += " ";
        }
        return s;
    }
};
// Time : O(n)
// Space : O(n)