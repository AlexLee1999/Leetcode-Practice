class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> list(cards.begin(), cards.end());
        return checkPossible(list);
    }
    bool checkPossible(vector<double>& cards) {
        if (cards.size() == 1) {
            return abs(cards[0] - 24) <= 0.1;
        }
        
        for (int i=0; i<cards.size(); ++i) {
            for (int j=i + 1; j<cards.size(); ++j) {
                vector<double> newCard;
                for (int k=0; k<cards.size(); ++k) {
                    if (k == i || k == j) {
                        continue;
                    }
                    newCard.push_back(cards[k]);
                }
                
                vector<double> poss = allPossible(cards[i], cards[j]);
                for (int k=0; k<poss.size(); ++k) {
                    newCard.push_back(poss[k]);
                    if (checkPossible(newCard)) {
                        return true;
                    }
                    newCard.pop_back();
                }
                
            }
        }
        return false;
    }
    vector<double> allPossible(double a, double b) {
        vector<double> res;
        if (a != 0) {
            res.push_back((double)b / (double)a);
        }
        if (b != 0) {
            res.push_back((double)a / (double)b);
        }
        res.push_back((double)a + (double)b);
        res.push_back((double)a * (double)b);
        res.push_back((double)a - (double)b);
        res.push_back((double)b - (double)a);
        
        return res;
    }
};