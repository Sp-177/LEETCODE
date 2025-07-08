class Solution {
public:
    class DSU {
    public:
        vector<int> parent;
        unordered_map<int, unordered_set<int>> restrictionMap;

        DSU(int n) {
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int x) {
            if (x != parent[x])
                parent[x] = find(parent[x]);  // Path compression
            return parent[x];
        }

        void merge(int u, int v) {
            int rootU = find(u);
            int rootV = find(v);
            if (rootU == rootV) return;

            // Always merge smaller restriction set into the larger one
            if (restrictionMap[rootU].size() < restrictionMap[rootV].size()) {
                swap(rootU, rootV);
            }

            parent[rootV] = rootU;

            // Merge restriction sets
            restrictionMap[rootU].insert(restrictionMap[rootV].begin(), restrictionMap[rootV].end());

            // Reverse propagation: anyone who restricts a member of rootU's group now restricts rootU
            for (int restrictedBy : restrictionMap[rootU]) {
                restrictionMap[restrictedBy].insert(rootU);
            }
        }
    };

    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        DSU dsu(n);

        // Build initial user-to-user restriction map
        for (const auto& r : restrictions) {
            int a = r[0], b = r[1];
            dsu.restrictionMap[a].insert(b);
            dsu.restrictionMap[b].insert(a);
        }

        vector<bool> result;

        for (const auto& req : requests) {
            int u = req[0], v = req[1];
            int rootU = dsu.find(u);
            int rootV = dsu.find(v);

            bool violatesRestriction =
                dsu.restrictionMap[rootU].count(rootV) ||
                dsu.restrictionMap[rootV].count(rootU);

            if (violatesRestriction) {
                result.push_back(false);
            } else {
                dsu.merge(u, v);
                result.push_back(true);
            }
        }

        return result;
    }
};
