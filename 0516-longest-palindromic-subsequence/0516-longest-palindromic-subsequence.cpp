class Solution {
public:
    int arr[1001][1001];
    int check(string &s1,int i,int j){
        if(i>j) return 0;
        if(j==i) return 1;

        if(arr[i][j]!=-1) return arr[i][j];

        if(s1[i]==s1[j]) return arr[i][j]=2+check(s1,i+1,j-1);
        else return arr[i][j]=max(check(s1,i+1,j),check(s1,i,j-1));
    }
    int longestPalindromeSubseq(string s1) {
        memset(arr,-1,sizeof(arr));
        return check(s1,0,s1.size()-1);
    }
};