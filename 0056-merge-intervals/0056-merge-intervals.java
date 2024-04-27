class Solution {
    public int[][] merge(int[][] arr) {
        Arrays.sort(arr, (a, b) -> a[0] - b[0]);
        List<int[]> merged = new ArrayList<>();
        int start = arr[0][0];
        int end = arr[0][1];
        merged.add(new int[]{start, end});
        for (int i = 1; i < arr.length; i++) {
            if (arr[i][0] <= end) {
                if (arr[i][1] > end) {
                    end = arr[i][1];
                    merged.get(merged.size() - 1)[1] = end;
                }
            } else {
                start = arr[i][0];
                end = arr[i][1];
                merged.add(new int[]{start, end});
            }
        }
        return merged.toArray(new int[merged.size()][]);
    }
}