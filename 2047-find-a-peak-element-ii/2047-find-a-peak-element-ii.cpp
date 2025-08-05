class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        auto get = [&](int r, int c) -> int {
            if (r < 0 || r >= n || c < 0 || c >= m) return -1;
            return mat[r][c];
        };

        int left = 0, right = m - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            // Find the row with the maximum element in the mid column
            int maxRow = 0;
            for (int i = 1; i < n; ++i) {
                if (mat[i][mid] > mat[maxRow][mid])
                    maxRow = i;
            }

            int midVal = mat[maxRow][mid];
            int leftVal = get(maxRow, mid - 1);
            int rightVal = get(maxRow, mid + 1);

            if (midVal > leftVal && midVal > rightVal) {
                return {maxRow, mid}; // Found peak
            } else if (midVal < rightVal) {
                left = mid + 1; // Move right
            } else {
                right = mid - 1; // Move left
            }
        }

        return {-1, -1}; // Should never reach here if at least one peak exists
    }
};
