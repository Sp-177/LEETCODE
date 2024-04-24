class Solution {
    public int tribonacci(int n) {
        if (n == 0) return 0;
        else if (n == 1 || n == 2) return 1;
        int num1 = 0, num2 = 1, num3 = 1, ans = 0;
        for (int i = 3; i <= n; i++) {
            ans = num1 + num2 + num3;
            num1 = num2;
            num2 = num3;
            num3 = ans;
        }
        return ans;
    }
}