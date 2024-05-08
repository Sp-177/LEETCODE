class Solution {
    public int distributeCandies(int[] candies) {
        Set<Integer> set = new HashSet<>();
        for (int i : candies) {
            set.add(i);
        }
        int size = set.size();
        int n = candies.length;
        return Math.min(size, n / 2);
    }
}