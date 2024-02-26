#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll 		long long
#define f 		first
#define s 		second
#define pb 		push_back
#define p 		push
#define vi		vector<int>
#define pii 		pair<int,int>
#define vpi		vector<pii>
#define vs		vector<string>
#define u_mi		unordered_map<int,int>
#define u_mc 		unordered_map<char,int>
#define u_ms		unordered_map<string,int>
#define u_si 		unordered_set<int>
#define u_sc		unordered_set<string>
#define u_ss		unordered_set<string>
#define ld		long double
#define d		double
#define all(x)		x.begin(),x.end()
#define que_max		priority_queue<int>
#define que_min		priority_queue<int,vi,greater<int>>
#define F(x,y,z)	for(int i=x;i<y;i=i+z)
#define Fa(x)		for(auto i:x)
#define vvi		vector<vi>
#define vc      vector<char>
#define vvc     vector<vc>
#define vb      	vector<bool>
#define vvb     	vector<vb>
#define print(a)	for(auto i:a){cout<<i<<" ";}cout<<endl



int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int t;
	cin>>t;
	while(t>0){
        int c;cin>>c;
        string s;cin>>s;
        //cout<<s<<endl;
        int x=0,y=0;
        for(int j=0;j<c;j++){
            if(s[j]=='B'){x=j;break;}
        }
        for(int j=c-1;j>=0;j--){
            if(s[j]=='B'){y=j;break;}
        }
        cout<<y-x+1<<endl;
        t--;
	}
	return 0;
}