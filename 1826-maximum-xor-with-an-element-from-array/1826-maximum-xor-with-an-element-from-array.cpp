class Node {
public:
    vector<Node*> child;
    Node() { child.resize(2, NULL); }
};

class Trie {
public:
    Node* root;
    Trie() { root = new Node(); }

    void insert(int num) {
        Node* temp = root;
        for (int i = 31; i >= 0; i--) {
            int mask = 1 << i;
            int bit = (mask & num) ? 1 : 0;
            if (temp->child[bit] == NULL)
                temp->child[bit] = new Node();
            temp = temp->child[bit];
        }
    }
};

class Solution {
public:
    int maxXor(int num, Node* node) {
        int res = 0;
        Node* temp = node;
        for (int i = 31; i >= 0; i--) {
            int mask = 1 << i;
            int bit = (mask & num) ? 1 : 0;
            if (temp->child[bit ^ 1]) {
                res <<= 1;
                res++;
                temp = temp->child[bit ^ 1];
            } else {
                res <<= 1;
                temp = temp->child[bit];
            }
        }
        return res;
    }

    vector<int> maximizeXor(vector<int>& arr, vector<vector<int>>& queries) {
        set<int> st(arr.begin(), arr.end());

        auto cmp = [&](vector<int>& a, vector<int>& b) -> bool {
            return a[1] < b[1];
        };

        Trie obj;
        vector<vector<int>> q;

        for (int i = 0; i < queries.size(); i++) {
            vector<int> v = queries[i];
            v.push_back(i); // add original index
            q.push_back(v);
        }

        sort(q.begin(), q.end(), cmp);

        auto it = st.begin();
        vector<int> ans(queries.size(), -1);

        for (int i = 0; i < q.size(); i++) {
            int xi = q[i][0];
            int ai = q[i][1];
            int idx = q[i][2];

            // insert elements from set which are ≤ ai
            while (it != st.end() && *it <= ai) {
                obj.insert(*it);
                ++it;
            }

            if (obj.root->child[0] != NULL || obj.root->child[1] != NULL) {
                ans[idx] = maxXor(xi, obj.root);
            }
        }

        return ans;
    }
};
