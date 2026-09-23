class Solution {
public:
    typedef pair<int,pair<int,int>>p;
    vector<vector<int>>dirs={
        {1,0},
        {0,1},
        {-1,0},
        {0,-1}
    };

    int m;
    int n;

    bool is_safe(int i,int j){
        if(i>=0 && i<m && j>=0 && j<n){
            return true;
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();

        priority_queue<p,vector<p>,greater<p> >pq;
        vector<vector<int>>result(m,vector<int>(n,1e9));

        pq.push({0,{0,0}});
        result[0][0]=0;

        while(!pq.empty()){
            int d=pq.top().first;
            auto coord=pq.top().second;
            int x=coord.first;
            int y=coord.second;

            pq.pop();

            for(auto &dir:dirs){
                int new_x=dir[0]+x;
                int new_y=dir[1]+y;

                if(is_safe(new_x,new_y)){
                    int new_d= abs(grid[new_x][new_y] - grid[x][y]);
                    int maxd=max(new_d,d);

                    if(maxd<result[new_x][new_y]){
                        pq.push({maxd,{new_x,new_y}});
                        result[new_x][new_y]=maxd;
                    }
                }
            }

        }

        return result[m-1][n-1];
    }
};