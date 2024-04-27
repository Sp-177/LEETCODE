class Solution {
    public int findRotateSteps(String ring, String key) {
      Map<Character, List<Integer>> m = new HashMap<>();
        int[][] dp = new int[ring.length()][key.length()];
        for (int[] row : dp)
            Arrays.fill(row, -1);
        
        for (int i = 0; i < ring.length(); i++) {
            char c = ring.charAt(i);
            if (!m.containsKey(c))
                m.put(c, new ArrayList<>());
            m.get(c).add(i);
        }
        
        return sol(ring, key, 0, 0, m, dp);
    }
    
    private int sol(String ring, String key, int index_key, int index_ring, Map<Character, List<Integer>> m, int[][] dp) {
        if (index_key == key.length()) return 0;
        if (index_ring == -1) index_ring = ring.length() - 1;
        if (index_ring == ring.length()) index_ring = 0;
        if (dp[index_ring][index_key] != -1) return dp[index_ring][index_key];
        
        char currentChar = key.charAt(index_key);
        List<Integer> positions = m.get(currentChar);
        int ans = Integer.MAX_VALUE;
        
        for (int i : positions) {
            int dist1 = Math.abs(index_ring - i);
            int dist2 = Math.min(index_ring, i) + ring.length() - Math.max(index_ring, i);
            int distance = Math.min(dist1, dist2);
            
            ans = Math.min(sol(ring, key, index_key + 1, i, m, dp) + 1 + distance, ans);
        }
        
        return dp[index_ring][index_key] = ans;
    }
}