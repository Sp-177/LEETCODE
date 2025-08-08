class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int>st1,st2;
        int  n=arr.size();
        vector<int>l(n),r(n);
        for(int i=0;i<n;i++){
            while(st1.size()&&arr[st1.top()]>arr[i])st1.pop();
            l[i]=(st1.size()?st1.top():-1);
            st1.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(st2.size()&&arr[st2.top()]>=arr[i])st2.pop();
            r[i]=(st2.size()?st2.top():n);
            st2.push(i);
        }
        for(int i:l)cout<<i<<" ";
        cout<<endl;
        for(int i:r)cout<<i<<" ";
        cout<<endl;

        long long ans=0,mod=1e9+7;
        for(int i=0;i<n;i++){
            long long left=i-l[i],right=r[i]-i;
            // cout<<left<<" "<<right<<endl;
            ans+=(arr[i]*((left*right)%mod))%mod;
            ans%=mod;
        }
        return ans;
    }
};