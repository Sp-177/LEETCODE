class Solution {
public:
    string removeKdigits(string num, int k) {
        string stack;
        for (char c : num) {
            while (!stack.empty() && k > 0 && stack.back() > c) {
                stack.pop_back();
                k--;
            }
            stack.push_back(c);
        }

        // Remove remaining k digits from end
        while (k-- > 0 && !stack.empty()) {
            stack.pop_back();
        }

        // Remove leading zeros
        int i = 0;
        while (i < stack.size() && stack[i] == '0') i++;
        string res = stack.substr(i);

        return res.empty() ? "0" : res;
    }
};
