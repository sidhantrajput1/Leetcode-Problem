class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        vector<int> arr = nums;
        int m = arr.size();

        for(int i=0;i<m;i++){

            // first element fix with boundary check
            if(i==0 && arr[i]==0 && (m==1 || arr[i+1]==0)){
                arr[i]=1;
                n--;
                continue;  
            }

            // last element fix with boundary check
            if(i==m-1 && arr[i]==0 && arr[i-1]==0){
                arr[i] = 1;
                n--;
                continue;
            }

            // middle elements -> added boundary safety
            if(i>0 && i<m-1 && arr[i]==0 && arr[i-1]==0 && arr[i+1]==0){
                arr[i] = 1;
                n--;
                continue;
            }
        }

        return n <= 0; // your logic corrected
    }
};
