import java.util.*;

public class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        Arrays.sort(nums);
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++)
            map.put(i, i);
        List<Integer> dp = new ArrayList<>(Collections.nCopies(nums.length, 1));
        int s = 1;
        int ind = 0;
        for (int i = 1; i < nums.length; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp.get(i) < dp.get(j) + 1) {
                    dp.set(i, dp.get(j) + 1);
                    map.put(i, j);
                }
            }
            if (s < dp.get(i)) {
                s = dp.get(i);
                ind = i;
            }
        }
        List<Integer> ans = new ArrayList<>();
        while (map.get(ind) != ind) {
            ans.add(nums[ind]);
            ind = map.get(ind);
        }
        ans.add(nums[ind]);
        return ans;
    }
}
