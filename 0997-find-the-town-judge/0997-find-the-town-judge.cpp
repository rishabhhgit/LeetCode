class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>trustKartaHai(n+1,0);
        vector<int>trustNahiKarta(n+1,0);

        for(auto &it:trust){
            int i=it[0];
            int j=it[1];

            trustKartaHai[j]++;
            trustNahiKarta[i]++;
        }
        for(int i=1;i<=n;i++){
            if(trustKartaHai[i]==n-1 && trustNahiKarta[i]==0) return i;
        }
        return -1;
    }
};