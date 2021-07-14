class Solution {
public:
    string simplifyPath(string path) {
        int len = path.length();
        if (len == 0 || len == 1) {
            return path;
        }
        int left = 0;
        int right = 1;
        string s;
        string retStr = "";
        stack<string> st;
        while (right <= len) {
            if (right == len || path[right] == '/') {
                s = path.substr(left + 1, right - left - 1);

                if (s == "..") {
                    if (!st.empty()) {
                        st.pop();
                    }
                }
                else if (s == "." || s == "") {
                    ;
                }
                else {
                    st.push(s);
                }
                left = right;
            }
            ++right;
        }
        if (st.empty()) {
            return "/";
        }
        while (!st.empty()) {
            cout <<st.top()<<' ';
            retStr = "/" + st.top() + retStr;
            st.pop();
        }
        return retStr;

    }
};
