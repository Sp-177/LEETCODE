class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> adj;
    vector<int> inTime, low;
    int timer = 0;

    void dfs(int node, int parent) {
        inTime[node] = low[node] = timer++;
        
        for (int child : adj[node]) {
            if (child == parent) continue;
            
            if (inTime[child] == -1) {
                dfs(child, node);
                low[node] = min(low[node], low[child]);

                if (low[child] > inTime[node]) {
                    ans.push_back({node, child});  // It's a bridge
                }
            } else {
                low[node] = min(low[node], inTime[child]);  // Back edge
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        inTime.assign(n, -1);
        low.assign(n, -1);

        for (auto& edge : connections) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, -1);
        return ans;
    }
};
