class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        queue<int> q;
        for(int i = 0; i < n; i++) {
            q.push(i); // push index
        }
        vector<int> ans(n);
        for(int i = 0; i < n ; i++) {
            int idx = q.front();
            q.pop();
            // popping the front and pushing into back
            int x = q.front();
            q.pop();
            q.push(x);
            ans[idx] = deck[i];
        }
        return ans;
    }
};