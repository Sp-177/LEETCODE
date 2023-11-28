#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        pair<int,int> func(vector<int>&i,vector<int>&s_i){
            pair<int,int> ans;
            int k=i.size();
            auto x=i.begin();
            auto y=i.end();
            for(int j=0;j<s_i.size();j++){
                auto z=find(x,y,s_i[j]);
                ans.first+=z-x+1;
                ans.second+=k-(z-x);
            }
            
            return ans;
        }

};
int main(){
    int size;cin>>size;
    vector<int>i;
    for(int j=0;j<size;j++){
        int k;cin>>k;
        i.push_back(k);
    }
    int query;cin>>query;
    vector<int>s_i;
    for(int j=0;j<query;j++){
        int k;cin>>k;
        s_i.push_back(k);
    }
    Solution sol;
    pair<int,int> x=sol.func(i,s_i);
    cout<<x.first<<" "<<x.second;
    return 0;
}