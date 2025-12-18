class Solution {
public:
    bool ifpossible(vector<int>& time, long long given_time, int totalTrips) {
        long long actualTrips = 0;
        for (auto &t : time) {
            actualTrips += given_time / t;
        }

        return actualTrips >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 1; 
        long long high = totalTrips * (long long) *min_element(time.begin(), time.end());

        while (low <= high) {
            long long mid_time = low + (high - low) / 2;

            if (ifpossible(time, mid_time, totalTrips)) {
                high = mid_time - 1;
            } else {
                low = mid_time + 1;
            }
        }

        return low;
    }
};