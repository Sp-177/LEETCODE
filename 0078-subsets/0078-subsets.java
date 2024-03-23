class Solution {
   public List<List<Integer>> subsets(int[] nums) {
        int s = nums.length;
        int n = (int) Math.pow(2, s) - 1;
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            List<Integer> v = new ArrayList<>();
            for (int j = 0; j < s; j++) {
                if ((i & (1 << j)) != 0) {
                    v.add(nums[j]);
                }
            }
            ans.add(v);
        }
        return ans;
    }

}