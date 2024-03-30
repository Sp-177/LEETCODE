class Solution {
     public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (map.containsKey(complement)) {
                return new int[]{Math.min(i, map.get(complement)), Math.max(i, map.get(complement))};
            }
            map.put(nums[i], i);
        }
        
        return new int[]{0, 0}; // Default return value if no solution found
    }
}