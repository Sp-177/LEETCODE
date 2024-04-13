class Solution {
     public int func(int[] heights) {
        Stack<Integer> dp = new Stack<>();
        dp.push(0);
        int n = heights.length;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            while (!dp.isEmpty()) {
                if (i != n && heights[i] == heights[dp.peek()]) {
                    break;
                }
                if (i != n && heights[i] > heights[dp.peek()]) {
                    dp.push(i);
                    break;
                } else {
                    int ci = dp.pop();
                    int x;
                    if (dp.isEmpty()) x = i;
                    else x = i - dp.peek() - 1;
                    ans = Math.max(ans, x * heights[ci]);
                }
            }
            dp.push(i);
        }
        return ans;
    }

    public int maximalRectangle(char[][] matrix) {
        int ans = 0;
        int n = matrix.length;
        int m = matrix[0].length;
        int[][] mat = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') mat[i][j] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i >= 1 && mat[i][j] == 1) mat[i][j] += mat[i - 1][j];
            }
            ans = Math.max(ans, func(mat[i]));
        }
        return ans;
    }
}