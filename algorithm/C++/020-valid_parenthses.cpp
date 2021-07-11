class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 1){
            return false;
        }
        if((s.length() & 1) != 0){
            return false;
        }
        stack<char> sta;
        for (int i=0; i<s.length(); ++i){
            if(s[i] == '(' || s[i] == '['|| s[i] == '{'){
               sta.push(s[i]);
            }
            else{
                if(sta.empty()){
                    return false;
                }
                char res = sta.top();
                if ((s[i] == ')' && res != '(') || (s[i] == ']' && res != '[') || (s[i] == '}' && res != '{' )){
                    return false;
                }
                sta.pop();
            }
        }
        if(sta.empty()){
            return true;
        }
        return false;
    }
};
