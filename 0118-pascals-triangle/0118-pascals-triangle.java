class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> v = new ArrayList<>();

        for (int i = 0; i < numRows; i++) {
            List<Integer> row = new ArrayList<>();
            row.add(1);
            if (i >= 1) {
                for (int j = 1; j < i; j++) {
                    row.add(v.get(i - 1).get(j) + v.get(i - 1).get(j - 1));
                }
                row.add(1);
            }
            v.add(row);
        }
        
        return v;
    }
}