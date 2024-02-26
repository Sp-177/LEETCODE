#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        long long sol(int s,int d,int k,vector<int>&v){
            int j=0;
            long long ans=0;
            //cout<<s+d*(k-1)<<endl;
            for(int i=s-1;i<s+d*(k-1);i++){
                if(j<k){j++;ans+=j*v[i];}
                else ans+=v[i];

                
            }
            return ans;
        } 
};
int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int n,q;cin>>n>>q;
        int s,d,k;
        vector<int>v(n);
        for(int j=0;j<n;j++)cin>>v[j];
        for(int j=0;j<q;j++){
            cin>>s>>d>>k;
            Solution S;
            long long ans=S.sol(s,d,k,v);
            cout<<ans<<" "<<endl;
        }
        cout<<endl;

    }
    return 0;
}