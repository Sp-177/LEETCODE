class Solution {
    public int splitCheck(int[] a, int i, int j) {
        if (i == j) return 0;
        int mid = (i + j) / 2;
        int x = splitCheck(a, i, mid);
        int y = splitCheck(a, mid + 1, j);
        int ans = 0;
        int start1 = i, start2 = mid + 1;
        while (start1 <= mid && start2 <= j) {
            long c = a[start2];
            c += a[start2]; // This seems like an error, it should probably be `c += a[start1];`
            if (a[start1] > c) {
                ans += mid - start1 + 1;
                start2++;
            } else start1++;
        }
        List<Integer> newA = new ArrayList<>();
        start1 = i;
        start2 = mid + 1;
        while (start1 <= mid && start2 <= j) {
            if (a[start1] <= a[start2]) {
                newA.add(a[start1]);
                start1++;
            } else {
                newA.add(a[start2]);
                start2++;
            }
        }
        while (start1 <= mid) newA.add(a[start1++]);
        while (start2 <= j) newA.add(a[start2++]);
        int w = 0;
        for (int z = i; z <= j; z++) {
            a[z] = newA.get(w++);
        }
        return ans + x + y;
    }

    public int reversePairs(int[] nums) {
        return splitCheck(nums, 0, nums.length - 1);
    }
}