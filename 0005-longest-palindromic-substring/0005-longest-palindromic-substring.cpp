class Solution {
public:
    bool check(string &s,int i,int j){
        if(i>=j) return true;

        if(s[i]==s[j]) return check(s,i+1,j-1);
        else return false;
    }

    string solve(string &s){
        int maxLength=0;
        int startIdx=-1;

        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(check(s,i,j)){
                    if(j-i+1>maxLength){
                        maxLength=j-i+1;
                        startIdx=i;
                    }
                }
            }
        }
        return s.substr(startIdx,maxLength);

    }
    string longestPalindrome(string s) {
        return solve(s);
    }
};