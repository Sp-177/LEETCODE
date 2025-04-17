#include <bits/stdc++.h>
using namespace std;

// Fast I/O
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int MAXN = 2e5 + 5;

vector<pair<int, int>> adj[MAXN];       // Adjacency list: node -> (child, weight)
vector<int> et;                         // Euler Tour array
vector<int> indexes[MAXN];              // Entry and exit times in Euler Tour
int timer = 0;

// Segment Tree Class
class SegmentTree {
private:
    vector<int> tree;
    int n;

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) >> 1;
        build(arr, 2 * node + 1, start, mid);
        build(arr, 2 * node + 2, mid + 1, end);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) >> 1;
        if (idx <= mid)
            update(2 * node + 1, start, mid, idx, val);
        else
            update(2 * node + 2, mid + 1, end, idx, val);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) >> 1;
        return query(2 * node + 1, start, mid, l, r) +
               query(2 * node + 2, mid + 1, end, l, r);
    }

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    void update(int idx, int val) {
        update(0, 0, n - 1, idx, val);
    }

    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};

// DFS Function
void dfs(int node, int parent) {
    indexes[node].push_back(timer++);
    for (auto& [child, wt] : adj[node]) {
        if (child == parent) continue;
        et.push_back(wt);
        dfs(child, node);
        et.push_back(-wt);
    }
    indexes[node].push_back(timer++);
}

class Solution {
public:
    vector<int> treeQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        FAST_IO;

        // Reset for multiple test cases (optional if needed)
        for (int i = 0; i <= n; ++i) {
            adj[i].clear();
            indexes[i].clear();
        }
        et.clear();
        timer = 0;

        // Build tree
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        et.push_back(0);  // initial
        dfs(1, 0);
        et.push_back(0);  // final

        SegmentTree seg(et);
        vector<int> ans;

        for (auto& q : queries) {
            if (q[0] == 2) {
                int idx = indexes[q[1]][0];
                ans.push_back(seg.query(0, idx));
            } else {
                int u = q[1], v = q[2], new_wt = q[3];
                int child = (indexes[u][0] > indexes[v][0]) ? u : v;
                int in = indexes[child][0];
                int out = indexes[child][1];
                seg.update(in, new_wt);
                seg.update(out, -new_wt);
            }
        }
        return ans;
    }
};
