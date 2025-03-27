class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int len = grid.size()-1;
        int count = 0;

        for(int i=0;i<=len;i++){

            int lo=0, hi=grid[i].size()-1,firstNegIdx=-1;
            
            // just finding the index of first negative element
            while(lo<=hi){
                int mid = lo + (hi-lo)/2;
                if(grid[i][mid]<0){
                    firstNegIdx = mid;
                    hi = mid-1;
                }
                else {// grid[mid]>0
                    lo = mid+1;
                } 
            }

            if(firstNegIdx == -1) continue;
            else count += grid[i].size() - firstNegIdx;
           
        }
        // cout<<count; 

        return count;
    }
};