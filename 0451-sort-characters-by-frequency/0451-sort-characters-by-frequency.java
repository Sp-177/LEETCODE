
class Solution {
    public String frequencySort(String s) {
        Map<Character, Integer> m = new HashMap<>();
        for (char i : s.toCharArray()) {
            m.put(i, m.getOrDefault(i, 0) + 1);
        }
        PriorityQueue<Map.Entry<Character, Integer>> pq = new PriorityQueue<>(
            (a, b) -> b.getValue() - a.getValue()
        );
        pq.addAll(m.entrySet());
        StringBuilder ans = new StringBuilder();
        while (!pq.isEmpty()) {
            Map.Entry<Character, Integer> entry = pq.poll();
            for (int i = 0; i < entry.getValue(); i++) {
                ans.append(entry.getKey());
            }
        }
        return ans.toString();
    }
}
