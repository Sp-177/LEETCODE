import java.util.Arrays;

public class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] left = new int[n];
        int[] right = new int[n];
        int[] ans = new int[n];
        
        left[0] = nums[0];
        right[n - 1] = nums[n - 1];
        
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] * nums[i];
            right[n - 1 - i] = right[n - i] * nums[n - 1 - i];
        }
        
        ans[0] = right[1];
        ans[n - 1] = left[n - 2];
        
        for (int i = 1; i < n - 1; i++) {
            ans[i] = left[i - 1] * right[i + 1];
        }
        
        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {1, 2, 3, 4};
        int[] result = solution.productExceptSelf(nums);
        System.out.println(Arrays.toString(result));
    }
}
