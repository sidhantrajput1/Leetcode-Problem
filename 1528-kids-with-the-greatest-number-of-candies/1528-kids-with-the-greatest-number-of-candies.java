class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int mx = candies[0];
        for(int i = 0 ; i < candies.length; i++) {
            if(candies[i] > mx) {
                mx = candies[i];
            }
        }
        List<Boolean> res = new ArrayList();
        for(int i = 0 ; i < candies.length; i++) {
            int num = candies[i] + extraCandies;
            if(num >= mx) {
                res.add(true);
            } else res.add(false);
        }
        return res;
    }
}