class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=word1.size();
        int j=word2.size();
        string ans="";
        while(j>0 && i>0){
            ans+=word1[word1.size()-i];
            ans+=word2[word2.size()-j];
            i--;
            j--;
        } 
        while(i>0){
            ans+=word1[word1.size()-i];
            i--;
        }  
        while(j>0){
            ans+=word2[word2.size()-j];
            j--;
        }
        return ans;
    }
};