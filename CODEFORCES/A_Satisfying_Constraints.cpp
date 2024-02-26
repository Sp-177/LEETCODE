#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int sol(int m,int M,unordered_set<int>&s){
            vector<int>ans;
            for(int i=m;i<=M;i++){
                if(s.count(i)==0){ans.push_back(i);}
            }
           cout<<ans.size();
            return 0;
        }

};
int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int n;cin>>n;
        unordered_set<int>s;
        int m=INT_MIN,M=INT_MAX;
        for(int j=0;j<n;j++){
            int x,y;
            cin>>x>>y;
            if(x==1){
                m=max(m,y);
            }
            else if(x==2){
                M=min(M,y);
            }
            else{
                s.insert(y);
            }
        }
        Solution S;
        cout<<S.sol(m,M,s)<<endl;
    }
    return 0;
}