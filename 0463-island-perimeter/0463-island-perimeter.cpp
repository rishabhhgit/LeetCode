class Solution {
public:
    vector<vector<int>>dirs={
        {0,1},
        {1,0},
        {-1,0},
        {0,-1}
    };
    int row;
    int col;
    bool isSafe(int i,int j){
        return i<row && j<col && i>=0 && j>=0;
    }
    int peri=0;
    void bfs(queue<pair<int,int>>&q,vector<vector<int>>& grid){
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();

            for(auto &it:dirs){
                int new_x=x+it[0];
                int new_y=y+it[1];
                if(!isSafe(new_x,new_y)){
                    peri++;
                }
                else{
                    if(grid[new_x][new_y]==0){
                        peri++;
                    }
                    else if(grid[new_x][new_y]==1){
                        grid[new_x][new_y]=-1;
                        q.push({new_x,new_y});
                    }
                }
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        row=grid.size();
        col=grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=-1 && grid[i][j]==1){
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    grid[i][j]=-1;
                    bfs(q,grid);
                }
            }
        }
        return peri;
    }
};