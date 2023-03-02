class Solution {
public:
    int compress(vector<char>& chars) {
        int idx = 1;
        char ch = chars[0];
        int count = 1;
        int write_idx = 0;
        while (true) {
            if (idx < chars.size() && ch != chars[idx]) {
                if (count == 1) {
                    chars[write_idx] = ch;
                    write_idx ++;
                    ch = chars[idx];
                    idx ++;
                } else {
                    
                    string s = to_string(count);
                    chars[write_idx] = ch;
                    write_idx ++;
                    for (int i=0; i<s.size(); ++i) {
                        chars[write_idx] = s[i];
                        write_idx ++;
                    }
                    ch = chars[idx];
                    count = 1;
                    idx ++;
                }
            } else if (idx < chars.size() && ch == chars[idx]) {
                count ++;
                idx ++;
            } else {
                break;
            }
        }
        if (count == 1) {
            chars[write_idx] = ch;
            write_idx ++;
            ch = chars[idx];
            idx ++;
        } else {
            string s = to_string(count);
            chars[write_idx] = ch;
            write_idx ++;
            for (int i=0; i<s.size(); ++i) {
                chars[write_idx] = s[i];
                write_idx ++;
            }
            ch = chars[idx];
            count = 1;
            idx ++;
        }
        return write_idx;
    }
};