class Solution {
public:
    int maxi=0;
    int row,col;
    vector<vector<int>>dirs={
        {1,0},
        {0,1},
        {0,-1},
        {-1,0}
    };

    bool is_safe(int x, int y){
        if(x>=0 && y>=0 && x<row && y<col) return true;
        return false;
    }
    void bfs(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&visited){
        queue<pair<int,int>>q;
        int count=0;
        q.push({i,j});
        visited[i][j]=true;

        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            count++;

            for(auto &it:dirs){
                int x_=x+it[0];
                int y_=y+it[1];

                if(is_safe(x_,y_)){
                    if(!visited[x_][y_] && grid[x_][y_]==1){
                        visited[x_][y_]=true;
                        q.push({x_,y_});
                    }
                }
            }
            maxi=max(maxi,count);

        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row=grid.size();
        col=grid[0].size();
    
        vector<vector<int>>visited(row,vector<int>(col,false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && !visited[i][j] ){
                    bfs(grid,i,j,visited);
                }
            }
        }
        return maxi;
    }
};