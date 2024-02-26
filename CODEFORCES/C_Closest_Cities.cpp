#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int sol(int start,int end,unordered_map<int,int>&map){
           int ans=0;
           while(start!=end){
            start=map[start];ans++;
           }
           return ans;
        }
};
int main(){
    int t;cin>>t;
    for (int i = 0; i < t; i++)
    {
        int count;cin>>count;
        vector<int>cities(count);
        unordered_map<int,int>map;
        for (int j = 0; j < count; j++)
        {
            cin>>cities[j];
        }
        //cout<<"X"<<endl;
         for (int j = 0; j < count; j++)
        {
            int d=INT_MAX;
             for (int k = j; k < count; k++)
            {
                if(j==k)continue;
                if(d>abs(cities[j]-cities[k])){
                    map[j]=k;
                    d=abs(cities[j]-cities[k]);
                }
            }
        }
        int x;cin>>x;
        for(int j=0;j<x;j++){
            int start,end;cin>>start>>end;
            Solution S;
            S.sol(min(start-1,end-1),max(start-1,end-1),map);
            cout<<min(abs(start-end),S.sol(start-1,end-1,map))<<endl;
        }

        
    }
    
    return 0;
}