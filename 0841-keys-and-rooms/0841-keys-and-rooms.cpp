class Solution {
public:
    void bfs(int currnode,vector<vector<int>>& rooms,vector<int>&visited){
        queue<int>q;
        visited[currnode]=1;
        q.push(currnode);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto &it:rooms[node]){
                if(visited[it]==0){
                    visited[it]=1;
                    q.push(it);
                }
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int>visited(rooms.size(),0);
       
        bfs(0,rooms,visited);
        for(auto &it:visited){
            if(it==0){
                return false;
            }
        }
        return true;
    }
};