class Solution {
public:
    unordered_map<int,vector<int>>adj;
    int check(int u,int v){
        vector<int>&ans=adj[u];
        for(int i=0;i<ans.size();i++){
            if(ans[i]==v) return true;
        }
        return false;
    }
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>connections(n,0);
        
        priority_queue<pair<int,int>>maxNetworkRank;
        for(auto &it:roads){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(auto &it:roads){
            int u=it[0];
            int v=it[1];
            connections[u]++;
            connections[v]++;
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(check(i,j)) maxi=max(maxi,connections[i]+connections[j]-1);
                
                else maxi=max(maxi,connections[i]+connections[j]);
            }
        }
        return maxi;
    }
};