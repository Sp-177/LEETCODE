class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        vector<int> cuts(n, 0);

        // Precompute palindrome substrings
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 || isPalindrome[i + 1][j - 1])) {
                    isPalindrome[i][j] = true;
                }
            }
        }

        // Compute minimum cuts
        for (int i = 0; i < n; i++) {
            if (isPalindrome[0][i]) {
                cuts[i] = 0;
            } else {
                int minCut = INT_MAX;
                for (int j = 0; j < i; j++) {
                    if (isPalindrome[j + 1][i]) {
                        minCut = min(minCut, cuts[j] + 1);
                    }
                }
                cuts[i] = minCut;
            }
        }

        return cuts[n - 1];
    }
};
