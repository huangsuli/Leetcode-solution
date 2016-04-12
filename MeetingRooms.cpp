/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class IntervalCompare {
public:
    bool operator() (Interval& lhs, Interval& rhs){
        return lhs.start > rhs.start;
    }
};
 
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        priority_queue<Interval, vector<Interval>, IntervalCompare> pq;
        for(int i = 0; i < intervals.size(); i++){
            pq.push(intervals[i]);
        }
        int temp = 0;
        for(int i = 0; i < intervals.size(); i++){
            cout << pq.top().start <<endl;
            if(temp > pq.top().start) return false;
            temp = pq.top().end;
            pq.pop();
        }
        return true;
    }
};
