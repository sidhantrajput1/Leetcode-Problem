class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        string str = "";
        int m=word1.size();
        int n=word2.size();
        int j=0;

        // case if both string are of same length
        for(int i=0;i<min(m,n);i++){
            str += word1[i];
            str += word2[j++];
        }

        if(m>n){
            // case when word1.size()>word2.size()
            for(int i=min(m,n);i<m;i++) str += word1[i];
        }else{
            // case when word2.size()>word1.size()
            for(int i=min(m,n);i<n;i++) str += word2[i];
        }

        return str;
    }
};