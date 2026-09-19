class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& nums) {
        int count=0;
        vector<int>indegree(numCourses);
        queue<int>q;
        unordered_map<int,vector<int>>adj;

        for(auto &it:nums){
            int u=it[0];
            int v=it[1];
            indegree[v]++;
            adj[u].push_back(v);
        }
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
                count++;
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto &it:adj[u]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                    count++;
                }
            }
        }
        return count==numCourses;
    }
};