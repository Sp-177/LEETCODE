class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        Arrays.sort(deck);
        int index = deck.length - 1;
        Deque<Integer> d = new LinkedList<>();
        d.add(deck[index--]);
        while (index >= 0) {
            int b = d.pollLast();
            d.addFirst(b);
            d.addFirst(deck[index]);
            index--;
        }
        int[] ans = new int[deck.length];
        int i = 0;
        Iterator<Integer> iterator = d.iterator();
        while (iterator.hasNext()) {
            ans[i++] = iterator.next();
            iterator.remove();
        }
        return ans;
    }
}