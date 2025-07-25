class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        // Dijkstra-style min-heap
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            int cost = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (x == n - 1 && y == m - 1)
                return cost;

            if (cost > dist[x][y])
                continue;

            for (int d = 0; d < 4; ++d) {
                int nx = x + dir[d][0];
                int ny = y + dir[d][1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int newCost = cost + grid[nx][ny];
                    if (newCost < dist[nx][ny]) {
                        dist[nx][ny] = newCost;
                        pq.push({newCost, {nx, ny}});
                    }
                }
            }
        }

        return -1;
    }
};
