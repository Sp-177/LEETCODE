#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        void sol(string&x,int b){
            for(int i=b;i>=0;){
                if(x[b]=='a'||x[b]=='e'||x[b]=='i'||x[b]=='o'||x[b]=='u'){
                    x=x.substr(b-1)+'.'+x.substr(b-1,x.size()-b+1);
                    i-=2;
                }
                else{
                    x=x.substr(b-2)+'.'+x.substr(b-2,x.size()-b+2);
                    i-=3;
                }
            }
        }
};
int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int b;cin>>b;
        string x;cin>>x;
        Solution s;
        s.sol(x,b-1);
        cout<<x<<endl;
    }
    return 0;
}