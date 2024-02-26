#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int sol(string&a_box,string&box){
            int cats=0,a_cats=0;
            int ans=0;
            for(int i=0;i<box.size();i++){
                if(box[i]=='1')cats++;
                if(a_box[i]=='1')a_cats++;
                if(box[i]!=a_box[i] &&box[i]=='1')ans++;
            }
            if(a_cats>cats)ans+=a_cats-cats;
            return ans;
        }
};
int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int s;cin>>s;
        string box,a_box;cin>>box>>a_box;
        //cout<<x<<y<<endl;
        Solution S;
        cout<<S.sol(a_box,box)<<endl;

    }
    return 0;
}