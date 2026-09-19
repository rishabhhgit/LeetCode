class Solution {
public:
    void bfs(queue<int>& q, vector<vector<int>>& nums, vector<int>& visited,
             unordered_map<int, vector<int>>& adj) {

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            for (auto& it : adj[x]) {
                if (!visited[it]) {
                    q.push(it);
                    visited[it]=true;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& nums) {
        int count = 0;
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (nums[i][j] == 1 && j!=i) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> visited(nums.size(), false);
        queue<int> q;
        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                q.push(i);
                bfs(q, nums, visited, adj);
                count++;
            }
        }

        return count;
    }
};