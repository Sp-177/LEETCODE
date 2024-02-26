#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int t;
	cin>>t;
	while(t>0)
    {
        int s1,s2,k;cin>>s1>>s2>>k;
        unordered_set<int> m1;
        unordered_set<int> m2;
        for(int i=0;i<s1;i++){
            int x;cin>>x;m1.insert(x);
        }
        for(int i=0;i<s2;i++){
            int x;cin>>x;m2.insert(x);
        }
        int x=0,y=0;
        for(int i=1;i<=k;i++){
            if(m1.find(i)!=m1.end())x++;
            if(m2.find(i)!=m2.end())y++;
            if(m1.find(i)==m1.end() &&m2.find(i)==m2.end())break;
        }
        if(x>=k/2 &&y>=k/2)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        t--;
    }
	return 0;
}