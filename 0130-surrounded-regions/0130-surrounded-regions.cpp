class Solution {
public:
    int row;
    int col;

    vector<vector<int>>dirs={
        {1,0},
        {0,1},
        {-1,0},
        {0,-1}
    };
    bool is_safe(int i,int j){
        if(i>=0 && j>=0 && i<row && j<col) return true;
        return false;
    }

    bool on_edge(int i,int j){
        if(i==0 || j==0 || i==row-1 || j==col-1) return true;
        return false;
    }
    void bfs(vector<vector<char>>& board,int i,int j){
        vector<pair<int,int>>temp;
        board[i][j]='X';
        queue<pair<int,int>>q;
        q.push({i,j});

        bool is_edge=false;

        while(!q.empty()){
            
            int x=q.front().first;
            int y=q.front().second;
            temp.push_back({x,y});
            q.pop();

            for(auto &it:dirs){
                int x_=x+it[0];
                int y_=y+it[1];

                if(is_safe(x_,y_) && board[x_][y_]=='O'){
                    if(on_edge(x_,y_)) is_edge=true;
                    q.push({x_,y_});
                    board[x_][y_]='X';
                    temp.push_back({x_,y_});
                }
            }
        }
        if(is_edge){
            for(int i=0;i<temp.size();i++){
                int x=temp[i].first;
                int y=temp[i].second;

                board[x][y]='O';

            }
        }
    }
    void solve(vector<vector<char>>& board) {
        row=board.size();
        col=board[0].size();
        for(int i=1;i<row-1;i++){
            for(int j=1;j<col-1;j++){
                if(board[i][j]=='O'){
                    bfs(board,i,j);
                }
            }
        }
    }
};