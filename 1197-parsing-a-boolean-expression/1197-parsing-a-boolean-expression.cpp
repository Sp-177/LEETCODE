#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Needed for std::find

class Solution {
public:
    bool calc(std::vector<int>& v, int ops) {
        if (ops == 1) {
            return v[0] ^ 1;
        } else if (ops == 2) {
            if (std::find(v.begin(), v.end(), 1) == v.end()) return 0;
            return 1;
        }
        if (std::find(v.begin(), v.end(), 0) == v.end()) return 1;
        return 0;
    }

    bool func(int start, int end, const std::string& exp) {
        // cout<<start<<" "<<end<<endl;
        int ops = 0;
        if (exp[start] == '!') ops = 1;
        else if (exp[start] == '|') ops = 2;

        std::vector<int> v;
        for (int i = start + 2; i < end; i++) {
            if (exp[i] == 'f') v.push_back(0);
            else if (exp[i] == 't') v.push_back(1);
            else if (exp[i] == ',') continue;
            else {
                int cnt = 0;
                int j = i + 1;
                while (j < end ) {
                    if (exp[j] == '(') cnt++;
                    else if (exp[j] == ')') cnt--;
                    if(cnt==0)break;
                    j++;
                }
                bool ans = func(i, j, exp);
                v.push_back(ans);
                i = j +1;
            }
        }

        return calc(v, ops);
    }

    bool parseBoolExpr(std::string expression) {
        if(expression.size()==1){
            if(expression[0]=='f')return false;
            return true;
        }
        return func(0, expression.size() - 1, expression);
    }
};
