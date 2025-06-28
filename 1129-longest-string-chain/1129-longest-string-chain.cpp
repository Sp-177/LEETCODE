class Solution {
public:
    vector<int> dp;
    unordered_map<string,int>mp;
    class Node {
    public:
        int ind;
        bool isEnd;
        vector<Node*> child;

        Node() : ind(-1), isEnd(false), child(26, nullptr) {}
    };

    class Trie {
    public:
        Node* root;
        Trie() { root = new Node(); }

        void insert(string& str, int index) {
            Node* temp = root;
            for (char c : str) {
                if (temp->child[c - 'a'] == nullptr)
                    temp->child[c - 'a'] = new Node();
                temp = temp->child[c - 'a'];
            }
            temp->isEnd = true;
            temp->ind = index;
        }

        int search(string& str) {
            Node* temp = root;
            for (char c : str) {
                if (temp->child[c - 'a'] == nullptr) return -1;
                temp = temp->child[c - 'a'];
            }
            return temp->ind;
        }
    };

    int func(vector<string>& words, int n, int index) {
        if (index == n) return 0;
        if (dp[index] != -1) return dp[index];

        int len = words[index].size();
        string str = words[index];
        int ans = 1;

        for (char c = 'a'; c <= 'z'; c++) {
            for (int i = 0; i <= len; i++) {
                string temp = str.substr(0, i) + c + str.substr(i);
                
                if (mp.count(temp)) {
                    ans = max(ans, func(words, n, mp[temp]) + 1);
                }
            }
        }
        return dp[index] = ans;
    }

    int longestStrChain(vector<string>& words) {
        // Trie* obj = new Trie();
        sort(words.begin(), words.end());
        int n = words.size();

        for (int i = 0; i < n; i++) mp[words[i]]=i;

        dp.resize(n, -1);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans = max(ans, func(words, n, i));
        }

        return ans;
    }
};
