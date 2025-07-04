class Solution {
public:
    vector<vector<int>> dp;

    bool match(const string& s, const string& p, int i, int j) {
        int n = s.size(), m = p.size();
        if (i == n && j == m) return true;
        if (j == m) return false;
        if (dp[i][j] != -1) return dp[i][j];

        bool firstMatch = (i < n) && (s[i] == p[j] || p[j] == '.');
        bool result;

        if (j + 1 < m && p[j + 1] == '*') {
            result = match(s, p, i, j + 2) || (firstMatch && match(s, p, i + 1, j));
        } else {
            result = firstMatch && match(s, p, i + 1, j + 1);
        }

        return dp[i][j] = result;
    }

    bool isMatch(string s, string p) {
        dp.assign(s.size() + 1, vector<int>(p.size() + 1, -1));
        return match(s, p, 0, 0);
    }
};
