import java.util.*;

public class Solution {
    public int maxSubArray(int[] nums) {
        long ans = nums[0];
        long sum = 0;
        
        for (int i = 0; i < nums.length; i++) {
            if (sum < 0) sum = 0;
            sum += nums[i];
            
            if (ans < sum || ans < nums[i]) {
                if (sum < nums[i]) ans = nums[i];
                else ans = sum;
            }
        }
        
        return (int) ans;
    }
}
