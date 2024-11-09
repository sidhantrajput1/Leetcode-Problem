class Solution {
    
    public int addDigits(int n) {

        if(n == 0) return 0;
        return 1 + ( n - 1 ) % 9;

        // int sum = 0;
        // while(n > 0) {
        //     int rem = n % 10;
        //     sum = sum + rem;
        //     n = n / 10;
        // }

        // int num = sum;
        // int sum2 = 0;
        // while(num > 0) {
        //     int rem1 = num % 10;
        //     sum2 =sum2 +  rem1;
        //     num = num / 10;
        //     if(num == 0) break;
        // }
        

        // return sum2; // this code is alsp true but test case 1018 gives wrong input
    }
}