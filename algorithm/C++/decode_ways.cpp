class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> table(n + 1, 0);
        table[0] = 1;
        if(s[0] == '0'){
            table[1] = 0;
        }
        else{
            table[1] = 1;
        }
        for (int i = 2; i < n + 1; ++i){
            if(s[i-1] != '0'){        //If s[i-1] == 0 cannot decode
            table[i] += table[i-1];
            }
            if((s[i-2] == '2' && (int(s[i-1]) <= 54)) || (s[i-2] == '1')){
                table[i] += table[i-2];
            }
        }
        return table[n];
    }
};
