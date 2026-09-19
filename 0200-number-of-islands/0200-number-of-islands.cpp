class Solution {
public:
    vector<vector<int>>dirs={
        {0,1},
        {1,0},
        {0,-1},
        {-1,0}
    };
    int row;
    int col;
    bool is_safe(int i, int j) { return i >= 0 && i < row && j >= 0 && j < col; }
    void bfs(vector<vector<int>>&visited,queue<pair<int,int>>&q,vector<vector<char>>& grid){
        
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            visited[i][j]=true;
            q.pop();
            for(auto &it:dirs){
                int new_x=i+it[0];
                int new_y=j+it[1];

                if(is_safe(new_x,new_y)){
                    if(!visited[new_x][new_y]){
                        if(grid[new_x][new_y]=='1'){
                            visited[new_x][new_y]=true;
                            q.push({new_x,new_y});
                        }
                    }
                }
            }
            
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        row=grid.size();
        col=grid[0].size();
        vector<vector<int>>visited(row,vector<int>(col,0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    bfs(visited,q,grid);
                    count++;
                }
            }
        }
        return count;
    }
};