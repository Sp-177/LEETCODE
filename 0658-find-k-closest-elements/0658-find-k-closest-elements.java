class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
       int n = arr.length;
        int[][] v = new int[n][2];
        for (int i = 0; i < n; i++) {
            v[i][0] = Math.abs(arr[i] - x);
            v[i][1] = i;
        }
        Arrays.sort(v, (a, b) -> a[0] - b[0]);
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            ans.add(arr[v[i][1]]);
        }
        ans.sort(null);
        return ans;
    }
}