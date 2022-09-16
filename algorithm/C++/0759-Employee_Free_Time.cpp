/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> meetings;
        for (int i=0; i<schedule.size(); ++i) {
            meetings.insert(meetings.end(), schedule[i].begin(), schedule[i].end());
        }
        sort(meetings.begin(), meetings.end(), [](Interval& a, Interval& b) {
            return a.start < b.start;
        });
        vector<Interval> occupied = {meetings[0]};
        for (int i=1; i<meetings.size(); ++i) {
            if (meetings[i].start > occupied.back().end) {
                occupied.push_back(meetings[i]);
            } else {
                occupied.back().end = max(occupied.back().end, meetings[i].end);
            }
        }
        int end = occupied[0].end;
        vector<Interval> ans;
        for (int i=1; i<occupied.size(); ++i) {
            Interval freeTime = Interval(end, occupied[i].start);
            ans.push_back(freeTime);
            end = occupied[i].end;
        }
        return ans;
    }
};
// Time : O(nlogn)
// Space : O(n)