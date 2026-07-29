class Solution {
public:
    bool dfs(int start,int end,unordered_map<int,vector<int>>&adj,vector<bool>&visited){
        if(start==end) return true;
        visited[start]=true;
        for(auto &it:adj[start]){
            if(!visited[it] ){
                if( dfs(it,end,adj,visited)) return true;
            }
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& nums) {
        unordered_map<int,vector<int>>adj;
        vector<bool>result;
        for(auto &it:pre){
            int x=it[0];
            int y=it[1];

            adj[x].push_back(y);
        }
        
        for(int i=0;i<nums.size();i++){
            vector<bool>visited(n,false);
            if(dfs(nums[i][0],nums[i][1],adj,visited)) result.push_back(true);
            else result.push_back(false);
        }
        return result;
        
    }
};