class Solution {
public:
bool check(map<char,int>&m,map<char,int>&n){
    for(auto  i:m){
        if(n[i.first]<i.second)return false;
    }
    return true;
}
    string minWindow(string s, string t) {
        int n=s.size(),m=t.size();
        if(n<m)return "";
        map<char,int>ma,new_ma;
        for(char c:t)ma[c]++;
        int start=0,end=0;
        bool ans=s!=t?false:true;
        int l=0,r=n-1;
        while(start<n&&end<n){
            // cout<<start<<' '<<end<<endl;
            new_ma[s[end++]]++;
            while(check(ma,new_ma)&&start<end){
                if(r-l+1>=end-start){
                    r=end-1;
                    l=start;
                    ans=true;
                }
                new_ma[s[start++]]--;
            }
    
        }
        return ans?s.substr(l,r-l+1):"";
    }
};