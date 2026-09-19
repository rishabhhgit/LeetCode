class Solution {
public:
    int m;
    int n;
    vector<vector<int>>dirs={
        {0,1},
        {1,0},
        {-1,0},
        {0,-1}
    };
    bool is_safe(int i,int j){
        return i>=0 && j>=0 && i<m && j<n;
    }
    void bfs(queue<pair<int,pair<int,int>>>&q,vector<vector<int>>&heights,vector<vector<int>>&arr){
        
        while(!q.empty()){
            int val=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;

            q.pop();

            for(auto &it:dirs){
                int x1=x+it[0];
                int y1=y+it[1];

                if(is_safe(x1,y1)){
                    if(arr[x1][y1]==1e9 && heights[x1][y1]>=val){
                        arr[x1][y1]=1;
                        q.push({heights[x1][y1],{x1,y1}});
                    }
                }
            }
        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>&heights) {

        m=heights.size();
        n=heights[0].size();

        vector<vector<int>>pacific(m,vector<int>(n,1e9));
        vector<vector<int>>atlantic(m,vector<int>(n,1e9));

        queue<pair<int,pair<int,int>>>qp;
        queue<pair<int,pair<int,int>>>qa;

        for(int i=0;i<m;i++){
            pacific[i][0]=1;
            qp.push({heights[i][0],{i,0}});

            atlantic[i][n-1]=1;
            qa.push({heights[i][n-1],{i,n-1}});
        }

        for(int i=0;i<n;i++){
            pacific[0][i]=1;
            qp.push({heights[0][i],{0,i}});
            
            atlantic[m-1][i]=1;
            qa.push({heights[m-1][i],{m-1,i}});
        }
        bfs(qa,heights,atlantic);
        bfs(qp,heights,pacific);

        vector<vector<int>>result;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(atlantic[i][j]==1 && pacific[i][j]==1){
                    result.push_back({i,j});
                }
            }
        }
        return result;
        
    }
};