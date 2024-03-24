class Solution {
   static class Pair {
        long first;
        int second;

        public Pair(long first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    public static long[] mostFrequentIDs(int[] nums, int[] freq) {
        int n = nums.length;
        long[] ans = new long[n];
        HashMap<Integer, Long> map = new HashMap<>();
        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> Long.compare(b.first, a.first));

        for (int i = 0; i < n; i++) {
            map.put(nums[i], map.getOrDefault(nums[i], 0L) + freq[i]);
            pq.offer(new Pair(map.get(nums[i]), nums[i]));

            while (!pq.isEmpty()) {
                if (!Objects.equals(map.get(pq.peek().second), pq.peek().first)) {
                    int x = pq.peek().second;
                    pq.poll();
                    pq.offer(new Pair(map.get(x), x));
                } else {
                    break;
                }
            }
            ans[i] = pq.peek().first;
        }
        return ans;
    }
};