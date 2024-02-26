#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t){
        int x,y;cin>>x>>y;
        if(x>1 &&y>1){
           if(x&1 && y&1)cout<<"No"<<endl;
           else if(x&1 || y&1){
            if(x&1){
                if(y/2==x)cout<<"No"<<endl;
                else cout<<"Yes"<<endl;
            }
            else if(y&1){
                if(x/2==y)cout<<"No"<<endl;
                else cout<<"Yes"<<endl;
            }
           }
           else {
             if(x/2==y&&y/2==x)cout<<"No"<<endl;
                else cout<<"Yes"<<endl;
           }
        }
        else cout<<"No"<<endl;
        t--;
    }
    return 0;
} // namespace std;
