class Solution {
    public static int mySqrt(int x) {

        int res =(int) Math.floor(Math.sqrt(x));
        return res;

        // if (x < 2) return x;

        // int start = 1;
        // int end = x / 2;
        // int ans = 0;

        // while(start <= end) {
        //     int mid = start + (end + start) / 2;
        //     if(mid <= mid / 2) {
        //         start = mid + 1;
        //         ans = mid;
        //     } else {
        //         end = mid - 1;
        //     }
        // }
        // return ans;

        
    }
    
}