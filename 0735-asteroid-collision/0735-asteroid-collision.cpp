class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int ast : asteroids) {
            bool destroyed = false;


            while (!st.empty() && ast < 0 && st.top() > 0) {
                if (st.top() < -ast) {
                    st.pop(); // right one destroyed
                    continue;
                } else if ( st.top() == -ast){
                    st.pop(); // both are destroyed
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break; // left one destroyed
                }
            } 

            if (!destroyed) {
                st.push(ast);
            }
        }

        vector<int> res(st.size());

        for (int i = st.size() - 1; i >= 0; --i) {
            res[i] = st.top();
            st.pop();
        }

        return res;
    }
};