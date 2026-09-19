class Solution {
public:
    bool bipart(int node,vector<int>&color,vector<vector<int>>adj){
        queue<int>q;
        color[node]=0;
        q.push(node);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int j=0;j<adj[curr].size();j++){
                int v=adj[curr][j];
                if(color[v]==-1){
                    color[v]=!color[curr];
                    q.push(v);
                }
                else if(color[v]==color[curr]){
                    return false;
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                if(!bipart(i,color,graph)) return false;
            }
        }
        return true;
    }
};