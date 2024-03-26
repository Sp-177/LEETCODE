class Solution {
   public static boolean check(int i, int j, List<String> grid) {
        for (int k = 0; k < grid.size(); k++) {
            if (grid.get(i).charAt(k) == 'Q' || grid.get(k).charAt(j) == 'Q') return false;
        }
        for (int k = i, l = j; k < grid.size() && l < grid.size(); k++, l++) {
            if (grid.get(k).charAt(l) == 'Q') return false;
        }
        for (int k = i, l = j; k >= 0 && l >= 0; k--, l--) {
            if (grid.get(k).charAt(l) == 'Q') return false;
        }
        for (int k = i, l = j; k < grid.size() && l >= 0; k++, l--) {
            if (grid.get(k).charAt(l) == 'Q') return false;
        }
        for (int k = i, l = j; k >= 0 && l < grid.size(); k--, l++) {
            if (grid.get(k).charAt(l) == 'Q') return false;
        }
        return true;
    }

    public static void sol(int i, List<String> grid, List<List<String>> ans) {
        if (i == grid.size()) {
            ans.add(new ArrayList<>(grid));
            return;
        }
        for (int k = 0; k < grid.size(); k++) {
            if (check(i, k, grid)) {
                StringBuilder sb = new StringBuilder(grid.get(i));
                sb.setCharAt(k, 'Q');
                grid.set(i, sb.toString());
                sol(i + 1, grid, ans);
                sb.setCharAt(k, '.');
                grid.set(i, sb.toString());
            }
        }
    }

    public static List<List<String>> solveNQueens(int n) {
        List<String> s = new ArrayList<>();
        for (int i = 0; i < n; i++) s.add(".");
        List<String> grid = new ArrayList<>(n);
        for (int i = 0; i < n; i++) grid.add(String.join("", s));
        List<List<String>> ans = new ArrayList<>();
        sol(0, grid, ans);
        return ans;
    }
}