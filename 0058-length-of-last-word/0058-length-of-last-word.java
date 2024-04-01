class Solution {
    public int lengthOfLastWord(String s) {
        int ans = 0;
        boolean f = false;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) != ' ') {
                f = true;
                ans++;
            }
            if (s.charAt(i) == ' ' && f)
                return ans;
        }
        return ans;
    }
}