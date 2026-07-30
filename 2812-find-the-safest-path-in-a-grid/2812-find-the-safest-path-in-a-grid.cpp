class Solution {
public:
    vector<vector<int>>dirs={
        {1,0},
        {0,1},
        {-1,0},
        {0,-1}
    };
    int row;
    int col;
    bool check(int target,vector<vector<int>>&distanceFromThief){
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        if(distanceFromThief[0][0]<target) return false;
        visited[0][0]=true;
        queue<pair<int,int>>q;
        q.push({0,0});
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            if(x==row-1 && y==col-1) return true;
            q.pop();
            for(auto &it:dirs){
                int new_x=x+it[0];
                int new_y=y+it[1];

                if(new_x < 0 || new_x >= row || new_y < 0 || new_y >= col || visited[new_x][new_y] ||
                    distanceFromThief[new_x][new_y] < target)
                        continue;
                else{
                    q.push({new_x,new_y});
                    visited[new_x][new_y]=true;
                }
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        row=grid.size();
        col=grid[0].size();
        vector<vector<int>>distanceFromThief(row,vector<int>(col,-1));
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        queue<pair<int,int>>q;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    visited[i][j]=true;
                    distanceFromThief[i][j]=0;
                }
            }
        }
        //so, till now we have added nodes in queue for multi source bfs
        //now we will calculate min distance from every thief node
        while(!q.empty()){
            int qsize=q.size();
            while(qsize--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();

                for(auto dir:dirs){
                    int new_x=x+dir[0];
                    int new_y=y+dir[1];
                    int val=distanceFromThief[x][y]+1;
                    if(new_x>=0 && new_x<row && new_y>=0 && new_y<col && !visited[new_x][new_y]){
                        q.push({new_x,new_y});
                        visited[new_x][new_y]=true;
                        distanceFromThief[new_x][new_y]=val;
                    }
                }
            }
        }
        //we have filled distanceFromThief
        //now we have to apply binary search
        int l=0;
        int r=400;
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;

            if(check(mid,distanceFromThief)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};