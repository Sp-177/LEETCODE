class Solution {
public:
    int longestConsecutive(vector<int>&a) {
        if(a.size()==0)return 0;
        sort(a.begin(),a.end());
    int ans=0,len=1;
    // for(int i:a)cout<<i<<' ';
    // cout<<endl;
    for(int i=1;i<a.size();i++){
        if(a[i]==a[i-1])continue;
        if(a[i]-a[i-1]==1)len++;
        else{
            ans=max(ans,len);
            len=1;
        }
    }

    return max(ans,len);}
};