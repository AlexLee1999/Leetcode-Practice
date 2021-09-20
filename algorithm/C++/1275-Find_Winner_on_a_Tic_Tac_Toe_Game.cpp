class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        
        int row[3] = {0, 0, 0};
        int col[3] = {0, 0, 0};
        int diag = 0;
        int antidiag = 0;
        for (int i = 0; i < moves.size(); ++i) {
            if (i % 2 == 1) {
                row[moves[i][0]] ++;
                col[moves[i][1]] ++;
                if (moves[i][0] == moves[i][1]) {
                    diag ++;
                }
                if (moves[i][0] + moves[i][1] == 2) {
                    antidiag ++;
                }
            } 
            else if (i % 2 == 0) {
                row[moves[i][0]] --;
                col[moves[i][1]] --;
                if (moves[i][0] == moves[i][1]) {
                    diag --;
                }
                if (moves[i][0] + moves[i][1] == 2) {
                    antidiag --;
                }
            }
        }
        for (int i=0; i<3; ++i) {
            if (row[i] == 3 || col[i] == 3 || diag == 3||antidiag == 3) {
                return "B";
            }
            else if (row[i] == -3 || col[i] == -3 || diag == -3||antidiag == -3) {
                return "A";
            }
        }
        if (moves.size() < 9) {
            return "Pending";
        }
        return "Draw";
    }
};