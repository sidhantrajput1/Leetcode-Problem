class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        //prev greatest element
        vector<int> prev(n);
        prev[0] = -1;
        int max = height[0];
        for(int i = 1; i < n; i++) {
            prev[i] = max;
            if(max < height[i]) max = height[i];
        }

        // next greatest element array -> prev as next
        prev[n-1] = -1;
        max = height[n-1];
        for(int i = n-2; i >= 0; i--) {
            if(max < prev[i] )prev[i] = max;
            if(max < height[i]) max = height[i];
        }

        // Calculting water
        int water = 0;
        for(int i = 1; i < n-1; i++) {
            if(height[i] < prev[i]) {
                water += (prev[i] - height[i]);
            }
        }

        return water;
    }
};