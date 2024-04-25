class Solution {
    public void setZeroes(int[][] matrix) {
     Set<Integer> rowSet = new HashSet<>();
        Set<Integer> colSet = new HashSet<>();
        int n = matrix.length;
        int m = matrix[0].length;
        
        // Find rows and columns with zeros
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    rowSet.add(i);
                    colSet.add(j);
                }
            }
        }
        
        // Set zeros for rows and columns containing zeros
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (rowSet.contains(i) || colSet.contains(j)) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // return matrix;   
    }
}