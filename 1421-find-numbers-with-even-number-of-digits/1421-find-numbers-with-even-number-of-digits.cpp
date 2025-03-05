class Solution {
public:

    int countNumber(int num) {
        num = abs(num);
        int count = 0;
        do {
            count++;
            num = num / 10;
        } while (num != 0);
        return count;
    }

    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int num : nums) {
            if(countNumber(num) % 2 == 0) {
                count++;
            }
        }
        return count;
    }
};