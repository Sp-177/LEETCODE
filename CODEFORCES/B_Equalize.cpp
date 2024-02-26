#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dif(vector<int>&v){
    int ans=0;
    unordered_map<int,int>m;
    for(auto i:v){m[i]++;ans=max(ans,m[i]);}
    return ans;
}
int sol(vector<int>&v,int i,unordered_set<int>&s){
    if(i==v.size()){
        return dif(v);
    }
    int ans=0;
    for(int j=1;j<=v.size();j++){
        if(s.find(j)==s.end()){
        s.insert(j);
        v[i]+=j;
        ans=max(ans,sol(v,i+1,s));
        v[i]-=j;
        s.erase(j);
        }

    }
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>v(n);
        unordered_set<int>s;
        for(int i=0;i<n;i++)cin>>v[i];
        cout<<sol(v,0,s)<<endl;


    }
    return 0;
}