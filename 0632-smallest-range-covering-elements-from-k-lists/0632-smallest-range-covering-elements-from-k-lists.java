import java.util.*;

class Solution {
    public int[] smallestRange(List<List<Integer>> nums) {
        int[] ans = new int[2];
        List<int[]> v = new ArrayList<>();
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < nums.get(i).size(); j++) {
                v.add(new int[]{nums.get(i).get(j), i});
            }
        }
        
        Collections.sort(v, (a, b) -> Integer.compare(a[0], b[0]));
        
        Map<Integer, Integer> s = new HashMap<>();
        
        int range = Integer.MAX_VALUE;
        int i = v.get(0)[1], j = 0;
        int first = 0, end = 0;
        
        while (j < v.size()) {
            int[] current = v.get(j);
            s.put(current[1], s.getOrDefault(current[1], 0) + 1);
            end = j;
            
            if (s.size() == n) {
                while (s.size() == n) {
                    int r = v.get(end)[0] - v.get(first)[0] + 1;
                    if (range > r) {
                        range = r;
                        ans[0] = v.get(first)[0];
                        ans[1] = v.get(end)[0];
                    }
                    i = v.get(first)[1];
                    s.put(i, s.get(i) - 1);
                    if (s.get(i) == 0) s.remove(i);
                    first++;
                }
            }
            
            j++;
        }
        return ans;
    }
}
