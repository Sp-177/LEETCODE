class Solution {
public:

    class DSU {
    public:
        vector<int> par;
        unordered_map<int, set<int>> rest;

        DSU(int n) {
            par.resize(n);
            iota(par.begin(), par.end(), 0);
        }

        int find(int x) {
            if (x != par[x])
                par[x] = find(par[x]);
            return par[x];
        }

        void merge(int x, int y) {
            int p1 = find(x), p2 = find(y);
            if (p1 == p2) return;

            // Merge smaller rest set into larger one
            if (rest[p1].size() < rest[p2].size()) {
                swap(p1, p2);
            }

            par[p2] = p1;
            rest[p1].insert(rest[p2].begin(), rest[p2].end());
            for(int i:rest[p1])rest[i].insert(p1);
        }
    };

    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        DSU dsu(n);

        // Build direct user-to-user restriction sets
        for (auto& r : restrictions) {
            int u = r[0], v = r[1];
            dsu.rest[u].insert(v);
            dsu.rest[v].insert(u);
        }

        vector<bool> ans;

        for (auto& r : requests) {
            int u = r[0], v = r[1];
            int pu = dsu.find(u), pv = dsu.find(v);

            bool blocked = false;

            // Check all nodes in pu's group against rest[pu]
            if (dsu.rest.count(pu) && (dsu.rest[pu].count(v) || dsu.rest[pu].count(pv))) {
                blocked = true;
            }
            if (!blocked && dsu.rest.count(pv) && (dsu.rest[pv].count(u) || dsu.rest[pv].count(pu))) {
                blocked = true;
            }

            if (blocked) {
                ans.push_back(false);
            } else {
                ans.push_back(true);
                dsu.merge(u, v);
            }
        }

        return ans;
    }
};
