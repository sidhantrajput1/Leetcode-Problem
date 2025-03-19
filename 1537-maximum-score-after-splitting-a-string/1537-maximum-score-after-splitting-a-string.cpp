class Solution {
public:
    int maxScore(string s) {
        int n = s.size();

        int countOnes = 0;
        int countZeros = 0;
        for(int i = 0; i < s.size(); i++) {
            if ( s[i] == '1') countOnes++;
        }
        
        int maxScore = 0;

        for(int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '0') countZeros++;
            else countOnes--;

            int score = countOnes + countZeros;
            maxScore = max(maxScore, score);
        }

        return maxScore;
    }
};