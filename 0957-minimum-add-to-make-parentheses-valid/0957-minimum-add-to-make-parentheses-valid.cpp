class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        int open=0,close=0;
        for(auto i:s){
            if(i=='(')open++;
            else{
                if(open>0){
                    open--;
                }
                else close++;
            }
        }
        return open+close;
    }
};