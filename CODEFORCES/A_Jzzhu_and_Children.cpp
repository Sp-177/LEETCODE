#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Solution{
    public:
        int func(queue<pair<int,int>>&q,int candy){
            int ans=0;
            while(!q.empty()){
                pair<int,int>x=q.front();
                q.pop();
                if(candy<x.first){
                    x.first=x.first-candy;
                    q.push(x);
                }
                ans=x.second;

            }
            return ans;
        }

};
int main(){
    int size,candy;
    cin>>size>>candy;
    queue<pair<int,int>>q;
    for(int i=0;i<size;i++){
        int c;cin>>c;
        pair<int,int>p;
        p.first=c;
        p.second=i+1;
        q.push(p);
    }
    Solution s;
    cout<<s.func(q,candy);
    return 0;
}