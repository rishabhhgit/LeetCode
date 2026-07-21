class Solution {
public:
    int arr[1001][1001];
    bool check(string &s,int i,int j){
        if(i>=j) return true;
        if(arr[i][j]!=-1) return arr[i][j];
        if(s[i]==s[j]) return arr[i][j]=check(s,i+1,j-1);
        else return arr[i][j] = false;
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
        memset(arr,-1,sizeof(arr));
        return solve(s);
    }
};