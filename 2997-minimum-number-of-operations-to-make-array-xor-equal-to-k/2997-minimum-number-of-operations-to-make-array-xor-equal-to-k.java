class Solution {
    public static int minOperations(int[] nums, int k) {
        int xr = 0;
        for (int i : nums)
            xr ^= i;
        return Integer.bitCount(xr ^ k);
    }
}