class Solution {
    public int maximumScore(int a, int b, int c) {
        int ans = 0;
        while ((a != 0 && b != 0) || (b != 0 && c != 0) || (c != 0 && a != 0)) {
            int x = Math.max(a, Math.max(b, c));
            int y = (x == a) ? Math.max(b, c) : (x == b) ? Math.max(a, c) : Math.max(a, b);
            int t = (x == a) ? a-- : (x == b) ? b-- : c--;
            t = (y == a) ? a-- : (y == b) ? b-- : c--;
            ans++;
        }
        return ans;
    }
}