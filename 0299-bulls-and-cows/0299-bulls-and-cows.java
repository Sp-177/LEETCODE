class Solution {
    public String getHint(String secret, String guess) {
        int[] map = new int[10];
        int bulls = 0;
        for (int i = 0; i < secret.length(); i++) {
            if (guess.charAt(i) != secret.charAt(i))
                map[guess.charAt(i) - '0']++;
            else
                bulls++;
        }
        int cows = 0;
        for (int i = 0; i < secret.length(); i++) {
            if (guess.charAt(i) != secret.charAt(i)) {
                if (map[secret.charAt(i) - '0'] > 0) {
                    cows++;
                    map[secret.charAt(i) - '0']--;
                }
            }
        }
        String ans = bulls + "A" + cows + "B";
        return ans; 
    }
}