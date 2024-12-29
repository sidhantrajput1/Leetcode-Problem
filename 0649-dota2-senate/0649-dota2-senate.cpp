class Solution {
public:
    string predictPartyVictory(string s) {
        queue<int> q;
        queue<int> r;
        queue<int> d;
        for(int i = 0; i < s.length(); i++) {
            q.push(i);
            if(s[i] == 'R') r.push(i);
            else d.push(i);
        }
        while(q.size() > 1) {
            if(s[q.front()] == 'X') q.pop();
            else if(s[q.front()] == 'R') {
                // check for victory
                if(d.size() == 0) return "Radiant";
                else { // take the right of next d
                    s[d.front()] = 'X';
                    d.pop();
                    // work is done
                    int x = q.front();
                    q.pop();
                    q.push(x);
                    int y = r.front();
                    r.pop();
                    r.push(y);
                }
            } else { // s[q.front()] == 'D'
                // check for victory
                if(r.size() == 0) return "Dire";
                else { // take the right of next d
                    s[r.front()] = 'X';
                    r.pop();
                    // work is done
                    int x = q.front();
                    q.pop();
                    q.push(x);
                    int y = d.front();
                    d.pop();
                    d.push(y);
                }
            }
        }
        if(s[q.front()] == 'R') return "Radiant";
        else return "Dire";
    }
};