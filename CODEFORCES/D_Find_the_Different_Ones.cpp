#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t>0){
        int s;cin>>s;
        vector<int>v(s);
        for(int i=0;i<s;i++){
            cin>>v[i];
        }
        int q;cin>>q;
        for(int i=0;i<q;i++){
            int x,y;cin>>x>>y;x--;y--;
            if(v[x]!=v[y])cout<<x+1<<" "<<y+1<<endl;
            else{
                bool say=false;
                while(x<y){
                    if(v[x]!=v[y]){say=true;break;}
                    y--;
                }
                if(say)cout<<x+1<<" "<<y+1<<endl;
                else cout<<-1<<" "<<-1<<endl;
            }
            
        }
        cout<<endl;
        t--;
    }
    return 0;
} // namespace std;

