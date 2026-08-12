class Solution {
public:
int arr[501][501];
int lcs(string word1,string word2,int i,int j){
    //base case
    if(i>=word1.size() || j>=word2.size()){
        return 0;
    }
    if(arr[i][j]!=-1) return arr[i][j];
    if(word1[i]==word2[j]){
        return arr[i][j]=1+lcs(word1,word2,i+1,j+1);
    }
    else{
        return arr[i][j]=max(lcs(word1,word2,i+1,j) , lcs(word1,word2,i,j+1));
    }

}

    int minDistance(string word1, string word2) {
        memset(arr,-1,sizeof(arr));
        int n1=word1.size();
        int n2=word2.size();
        if(n1==0) return n2;
        if(n2==0) return n1;

        int longestSub=lcs(word1,word2,0,0);
        return ((n1-longestSub)+(n2-longestSub));
    }
};