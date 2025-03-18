class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currentAlt = 0;
        int highestAlt = 0;
        
        for(int i = 0; i < gain.size(); i++) {
            currentAlt = currentAlt + gain[i];
            highestAlt = max(highestAlt, currentAlt);
        }

        return highestAlt;
    }
};