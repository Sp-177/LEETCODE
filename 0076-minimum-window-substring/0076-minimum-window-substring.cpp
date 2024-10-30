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
        int l=0,len=INT_MAX;
        int cnt=0;
        while(start<n&&end<n){
            // cout<<start<<' '<<end<<endl;
            if(ma[s[end]]>0)cnt++;
            ma[s[end]]--;
            while(cnt==m){
                if(len>=end-start+1){
                    len=end-start+1;
                    l=start;
                }
                ma[s[start]]++;
                if(ma[s[start++]]>0)cnt--;
                
            }
            end++;
        }
        return len==INT_MAX?"":s.substr(l,len);
    }
};