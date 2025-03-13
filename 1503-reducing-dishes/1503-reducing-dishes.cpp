class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        
        int n = satisfaction.size();
        int sum = 0;
        int total = 0;
        
        // Traverse from the end and accumulate the sum only if it increases the result
        for (int i = n - 1; i >= 0; i--) {
            // If adding the current satisfaction makes the total greater, we keep adding
            if (sum + satisfaction[i] > 0) {
                sum += satisfaction[i];
                total += sum;
            }
        }

        return total;
    }
};