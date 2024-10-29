class Solution {
    public int maxArea(int[] height) {
        int st = 0;
        int end = height.length - 1;

        int maxCap = 0;

        while(st < end) {
            int h = Math.min(height[st], height[end]);

            int width = end - st ;

            int currCap = h * width;

            maxCap = Math.max(currCap, maxCap);

            if(height[st] < height[end]) {
                st++;
            } else {
                end--;
            }
        }

        return maxCap;
    }
}