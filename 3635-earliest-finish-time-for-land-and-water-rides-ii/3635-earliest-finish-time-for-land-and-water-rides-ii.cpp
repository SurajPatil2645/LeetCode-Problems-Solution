class Solution {
private:
    int solveOneWay(const vector<pair<int, int>>& firstRides, const vector<pair<int, int>>& secondRides) {
        int m = secondRides.size();
        
        vector<int> prefMinDur(m);
        prefMinDur[0] = secondRides[0].second;
        for (int i = 1; i < m; ++i) {
            prefMinDur[i] = min(prefMinDur[i - 1], secondRides[i].second);
        }
        
        vector<int> suffMinFinish(m);
        suffMinFinish[m - 1] = secondRides[m - 1].first + secondRides[m - 1].second;
        for (int i = m - 2; i >= 0; --i) {
            suffMinFinish[i] = min(suffMinFinish[i + 1], secondRides[i].first + secondRides[i].second);
        }
        
        int minTotalFinish = INT_MAX;
        
        for (const auto& ride : firstRides) {
            int finish1 = ride.first + ride.second;
            
            int low = 0, high = m - 1, splitIdx = m;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (secondRides[mid].first > finish1) {
                    splitIdx = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            
            if (splitIdx > 0) {
                minTotalFinish = min(minTotalFinish, finish1 + prefMinDur[splitIdx - 1]);
            }
            
            if (splitIdx < m) {
                minTotalFinish = min(minTotalFinish, suffMinFinish[splitIdx]);
            }
        }
        
        return minTotalFinish;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, 
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        
        vector<pair<int, int>> land(n), water(m);
        for (int i = 0; i < n; ++i) land[i] = {landStartTime[i], landDuration[i]};
        for (int i = 0; i < m; ++i) water[i] = {waterStartTime[i], waterDuration[i]};
        
        sort(land.begin(), land.end());
        sort(water.begin(), water.end());
        
        int planA = solveOneWay(land, water);
        int planB = solveOneWay(water, land);
        
        return min(planA, planB);
    }
};