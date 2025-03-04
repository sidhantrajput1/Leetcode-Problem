class Solution {
public:
    
    bool checkPowersOfThree(int n) {
        // 1. Convert the number n to its ternary (base-3) representation.
        // 2. Check if all digit in the base-3 representation are 0 and 1
        // 3. if any digit is greater than 2 or more return false;
        // 4. otherwise return true;
        while(n > 0) {
            int rem = n % 3;
            if(rem == 2) return false;
            n = n / 3;
        }
        return true;
    }
};