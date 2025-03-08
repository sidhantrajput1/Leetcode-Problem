class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        
        int i = 0, j = 0;
        int ops = k;
        int count = 0;

        while( j < n) {
            if(blocks[j] == 'W') count++;

            if (j - i + 1 == k) {
                ops = min(count, ops);

                if(blocks[i] == 'W') count--;
                i++;
            }
            j++;
        }
        return ops;
    }
};