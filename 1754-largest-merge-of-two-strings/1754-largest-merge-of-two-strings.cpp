class Solution {
public:
    string largestMerge(string word1, string word2) {
        int i=0;
        int j=0;
        string ans="";
        while(i<word1.size() && j<word2.size()){
            if(word1.substr(i) > word2.substr(j)){
                ans+=word1[i];
                i++;
            }
            else{
                ans+=word2[j];
                j++;
            }
        }

        while(i<word1.size()){
            ans+=word1[i];
            i++;
        }
        while(j<word2.size()){
            ans+=word2[j];
            j++;
        }

        return ans;
    }
};