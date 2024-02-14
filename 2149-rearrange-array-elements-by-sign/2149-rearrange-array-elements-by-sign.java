class Solution {
    public int[] rearrangeArray(int[] nums) {
        int ans[]=new int [nums.length]; 
         int x = 0;
        int y = 1;
        for (int i : nums) {
            if (i > 0) {
                ans[x]=i;
                x += 2;
            } else {
                ans[y]=i;
                y += 2;
            }
        }
        return ans;
    
    }
}