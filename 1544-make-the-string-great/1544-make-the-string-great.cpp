class Solution {
public:
    string makeGood(string s) {
        stack<char>stk;
        for(char i:s){
            if(!stk.empty()&&char(tolower(i))==char(tolower(stk.top())) &&(int(i)!=int(stk.top()))){stk.pop();}
            else stk.push(i);
        }
        string ans="";
        while(!stk.empty()){ans=stk.top()+ans;stk.pop();}
        return ans;
    }
};