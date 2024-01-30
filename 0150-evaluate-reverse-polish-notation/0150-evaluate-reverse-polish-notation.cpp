class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(auto i: tokens){
            
            if(!s.empty() && (i=="+"||i=="-"||i=="*"||i=="/")){
                int t1=s.top();
                s.pop();
                int t2=s.top();
                s.pop();
                if(i=="+")s.push(t1+t2);
                else if(i=="-")s.push(t2-t1);
                else if(i=="*")s.push(t2*t1);
                else s.push(t2/t1);
            }
            else s.push(stoi(i));
        }
        return s.top();
    }
};