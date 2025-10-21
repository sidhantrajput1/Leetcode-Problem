class Solution {
public:
    string simplifyPath(string path) {
        string token = "";

        stringstream ss(path);
        stack<string> st;

        while (getline(ss, token, '/')) {
            // Skip empty or current directory
            if (token == "" || token == ".") continue;

            // Go up one level if possible
            if (token == "..") {
                if (!st.empty()) st.pop();
            } 
            // Otherwise, push valid directory name
            else {
                st.push(token);
            }
        }

        if (st.empty()) return "/";

        string result = "";
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        return result;
    }
};