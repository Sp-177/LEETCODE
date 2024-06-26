public class Solution {
    public int appendCharacters(String s, String t) {
        int i = 0, j = 0, ans = 0;
        while (i < s.length() && j < t.length()) {
            if (s.charAt(i) == t.charAt(j)) {
                j++;
                ans++;
            }
            i++;
        }
        return t.length() - ans;
    }
}
