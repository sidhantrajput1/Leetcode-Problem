class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for (int ast : asteroids) {
            bool destroyed = false;


            while (!st.empty() && ast < 0 && st.back() > 0) {
                if (st.back() < -ast) {
                    st.pop_back(); // right one destroyed
                    continue;
                } else if ( st.back() == -ast){
                    st.pop_back(); // both are destroyed
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break; // left one destroyed
                }
            } 

            if (!destroyed) {
                st.push_back(ast);
            }
        }

        // vector<int> res(st.size());

        // for (int i = st.size() - 1; i >= 0; --i) {
        //     res[i] = st.top();
        //     st.pop();
        // }

        return st;
    }
};