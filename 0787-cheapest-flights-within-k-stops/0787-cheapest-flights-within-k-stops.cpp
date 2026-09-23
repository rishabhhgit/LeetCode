class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // {distance ,{from,{to,k}}
        typedef pair<int,pair<int,int>>p;
        priority_queue<p,vector<p>,greater<p>>pq;
        unordered_map<int,vector<pair<int,int>> >adj;
        for(auto &v:flights){
            int source=v[0];
            int destination=v[1];
            int weight=v[2];
            adj[source].push_back({destination,weight});
        }

        pq.push({0,{src,0}});
        vector<vector<int>>result(n,vector<int>(k+2,1e9));
        result[src][0]=0;

        while(!pq.empty()){
            int val=pq.top().first;
            int node=pq.top().second.first;
            int k_took=pq.top().second.second;

            pq.pop();

            if (node == dst) return val;

            if (k_took > k) continue;

            for(auto &it:adj[node]){
                int new_node=it.first;
                int wt=it.second;

                if(wt+val<result[new_node][k_took+1]){
                    result[new_node][k_took+1]=wt+val;
                    pq.push({wt+val,{new_node,k_took+1}});
                }
            }

        }
        return -1;
    }
};