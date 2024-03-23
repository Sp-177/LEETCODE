class Solution {
   public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> output = new ArrayList<>();
        solve(0, ans, nums, output);
        return ans;
    }

    private void solve(int i, List<List<Integer>> ans, int[] nums, List<Integer> output) {
        ans.add(new ArrayList<>(output));
        for (int j = i; j < nums.length; j++) {
            if (j > i && nums[j - 1] == nums[j])
                continue;

            output.add(nums[j]);
            solve(j + 1, ans, nums, output); // Pass j+1 instead of i+1

            output.remove(output.size() - 1);
        }
    }
}