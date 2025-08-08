class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>st;
        for(char c:num){
            int n=c-'0';
            while(k>0&&st.size()&&st.top()>n){
                st.pop();
                k--;
            }
            st.push(n);
        }
        while(k>0){
            st.pop();
            k--;
        }
        string ans="";
        while(st.size()){
            ans+=to_string(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int ind=0;
        for(char c:ans){
            if(c!='0')break;
            ind++;
        }
        
        ans=ans.substr(ind);
        if(ans.size()==0)ans="0";
        return ans;
    }
};


