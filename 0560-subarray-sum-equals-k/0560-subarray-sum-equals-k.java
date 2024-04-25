class Solution {
    public int subarraySum(int[] nums, int k) {
          int presum = 0;
        Map<Integer, Integer> m = new HashMap<>();
        m.put(0, 1);
        int ans = 0;
        
        for (int i = 0; i < nums.length; i++) {
            presum += nums[i];
            ans += m.getOrDefault(presum - k, 0);
            m.put(presum, m.getOrDefault(presum, 0) + 1);
        }
        
        return ans;
    }
}