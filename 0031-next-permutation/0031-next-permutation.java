class Solution {
    public void nextPermutation(int[] nums) {
        boolean f = false;
        int index = 0;
        for (int i = nums.length - 1; i >= 1; i--) {
            if (nums[i] > nums[i - 1]) {
                index = i - 1;
                f = true;
                break;
            }
        }

        if (f) {
            int least_max = Integer.MAX_VALUE;
            int index1 = index + 1;
            for (int i = index + 1; i < nums.length; i++) {
                if (nums[i] > nums[index]) {
                    least_max = Math.min(least_max, nums[i]);
                    index1 = (least_max == nums[i]) ? i : index1;
                }
            }
            int temp = nums[index];
            nums[index] = nums[index1];
            nums[index1] = temp;
            Arrays.sort(nums, index + 1, nums.length);
        } else {
            Arrays.sort(nums);
        }
    }
}