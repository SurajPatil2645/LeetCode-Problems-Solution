class Solution {
public:
    int removeCoveredIntervals(std::vector<std::vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        
        int remaining = intervals.size();
        int max_end = 0;
        
        for (const auto& interval : intervals) {
            if (interval[1] <= max_end) {
                remaining--;
            } else {
                max_end = interval[1];
            }
        }
        
        return remaining;
    }
};