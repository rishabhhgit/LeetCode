class Solution {
public:
    void dfs(int u,vector<bool>&visited,unordered_map<int,vector<int>>&adj){
        visited[u]=true;

        for(auto &it:adj[u]){
            if(!visited[it]){
                dfs(it,visited,adj);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>ans;
        unordered_map<int,vector<int>>adj;
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
        }

        for(int i=0;i<n;i++){
            vector<bool>visited(n,false);
            vector<int>ancestors;
            dfs(i,visited,adj);
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(visited[j]){
                    ancestors.push_back(j);
                }
            }
            ans.push_back(ancestors);
        }
        return ans;
    }
};