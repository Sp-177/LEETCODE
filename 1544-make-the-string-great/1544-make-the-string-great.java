class Solution {
    public String makeGood(String s) {
         Stack<Character> stk = new Stack<>();
        for (char i : s.toCharArray()) {
            if (!stk.isEmpty() && Character.toLowerCase(i) == Character.toLowerCase(stk.peek()) &&
                    (i != stk.peek())) {
                stk.pop();
            } else {
                stk.push(i);
            }
        }
        StringBuilder ans = new StringBuilder();
        while (!stk.isEmpty()) {
            ans.insert(0, stk.pop());
        }
        return ans.toString();
    }
}