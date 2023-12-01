class Solution {
public:
bool flag=false;
bool alpha = false;
bool plus = false;
    int solve(string s,int ind,int pre){
        if(ind == s.size() || (alpha&&!isdigit(s[ind]))){
            if(flag){
                return -1*pre;
            }
            return pre;
        }
        if(s[ind]=='.'){
            if(flag){
                return -1*pre;
            }
            return pre;
        }
        if(flag&&plus){
            return 0;
        }
        if(!alpha){
            if((s[ind]>='a'&&s[ind]<='z') || (s[ind]>='A'&&s[ind]<='Z')){
                return pre;
            }
        }
        if(s[ind]=='-'){
            if(ind+1<s.size()&&!isdigit(s[ind+1]))
            return 0;
            flag=true;
            return solve(s,ind+1,pre);
        }
        if(s[ind]=='+'){
            if(ind+1<s.size()&&!isdigit(s[ind+1]))
            return 0;
            plus = true;
            return solve(s,ind+1,pre);
        }
        
        int ans = pre;
        if(isdigit(s[ind])){
            alpha=true;
            ans = s[ind]-'0';
            if(pre>(INT_MAX-ans)/10){
                if(flag){
                    return INT_MIN;
                }
                return INT_MAX;
            }
            
            ans = pre*10 + ans;
        }
        return solve(s,ind+1,ans);
        //return ans;
    }
    int myAtoi(string s) {
        int ans = solve(s,0,0);
        return ans;
    }
};