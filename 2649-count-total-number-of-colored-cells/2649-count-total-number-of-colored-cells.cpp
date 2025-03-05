class Solution {
public:
    long long coloredCells(int n) {
        if(n==1) return 1;
        long num = 1;
        for(int i = 1; i < n; i++) {
            num = i * 4 + num;
        }
        return num;
    }
};