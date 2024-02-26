#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int t;
	cin>>t;
	while(t--){
        int n;cin>>n;
         //cout<<n;
        bool flag=true;
        vector<string>v(n);
        for(int i=0;i<n;i++){
            
                cin>>v[i];
                // cout<<v[i][j];
            
        }
        for(int i=0;i<n;i++){bool b=false;
            for(int j=0;j<n;j++){
                if(v[i][j]=='1'){
                //   cout<<i<<j<<endl;
                    if(v[i+1][j]=='1' && v[i][j+1]=='1' &&v[i+1][j+1]=='1'){
                        flag=false;
                    }
                    b=true;
                    break;
                }
                if(b)break;
            }

        }
        if(!flag)cout<<"SQUARE"<<endl;
        else cout<<"TRIANGLE"<<endl;
	}
	return 0;
}