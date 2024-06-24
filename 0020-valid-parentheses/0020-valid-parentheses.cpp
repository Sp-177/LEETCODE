class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){st.push(i);}
            else{
                if(st.empty()||((s[i]==')'?s[st.top()]=='(':s[i]==']'?s[st.top()]=='[':s[st.top()]=='{')==false)){return false;}
                else{
                    st.pop();
                }
            }
        }
        return (st.size()==0);
    }
};