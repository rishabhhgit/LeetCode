class Solution {
public:
    int arr[1001][1001];
    int check(string &s1, string &s2,int i,int j){
        if(i>=s1.size() || j>=s2.size()) return 0;
        if(arr[i][j]!=-1) return arr[i][j];
        if(s1[i]==s2[j]) return arr[i][j]=1+check(s1,s2,i+1,j+1);
        return arr[i][j]=max(check(s1,s2,i+1,j),check(s1,s2,i,j+1));
    }
    int longestPalindromeSubseq(string s1) {
        string s2=s1;
        reverse(s2.begin(),s2.end());
        memset(arr,-1,sizeof(arr));
        return check(s1,s2,0,0);
    }
};