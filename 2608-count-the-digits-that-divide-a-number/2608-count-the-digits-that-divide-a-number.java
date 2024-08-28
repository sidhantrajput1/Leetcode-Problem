class Solution {
    public static int countDigits(int num) {
        int count  = 0;
        int rem = 0;
        
        int res = num;
        while(res > 0) {
            rem = res % 10;
            res = res / 10;
            if( num % rem == 0) ++count;
        }

        return count;
    }
}