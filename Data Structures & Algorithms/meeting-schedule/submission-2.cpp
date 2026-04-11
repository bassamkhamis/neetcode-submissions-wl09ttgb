/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            Interval& A =intervals[i];
            for (int j = i + 1; j < n; j++) {
                Interval& B =intervals[j];
                if (A.end > B.start && B.end > A.start) {
                    return false;
                }
            }
        }
        return true;
    }
};
