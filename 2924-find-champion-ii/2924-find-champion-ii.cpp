class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n,0);
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            indegree[v]++;
        }
        int ans=-1;
        queue<int>q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        if(q.size()==1) return q.front();
        else return -1;
    }
};