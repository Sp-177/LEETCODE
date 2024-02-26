#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long m=1e9+7;
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int x,y;
        bool s=true;
        for(int j=0;j<4;j++){
            int a,b;
            cin>>a>>b;
            if(s){x=a;y=b;s=false;}
            else if(x==a){
                long long ans=(y-b)*(y-b);
                cout<<(ans)%m<<endl;
            }
        }
    }
    return 0;
}