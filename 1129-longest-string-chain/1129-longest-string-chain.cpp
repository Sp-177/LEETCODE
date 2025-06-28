class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> dp;
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        int maxLen = 1;

        for (const string& word : words) {
            int best = 0;
            for (int i = 0; i < word.size(); ++i) {
                string prev = word.substr(0, i) + word.substr(i + 1);
                best = max(best, dp[prev]);
            }
            dp[word] = best + 1;
            maxLen = max(maxLen, dp[word]);
        }

        return maxLen;
    }
};
