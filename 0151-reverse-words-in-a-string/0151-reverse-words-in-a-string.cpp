class Solution {
public:
    string reverseWords(string s) {
        
        vector<string> arr;
        stringstream ss(s);
        string str;

        while(ss>>str){
            arr.push_back(str);
            cout<<str<<" ";
        }

        reverse(begin(arr),end(arr));

        string ans="";
        for(auto &ele : arr){
            string temp = ele + " ";
            ans.append(temp);
        }

        ans.pop_back();
        return ans;
    }
};