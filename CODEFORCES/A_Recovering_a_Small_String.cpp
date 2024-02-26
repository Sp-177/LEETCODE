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
#define F(x,y,z,i)	for(int i=x;i<y;i=i+z)
#define Fa(x,i)		for(auto i:x)
#define vvi		vector<vi>
#define vc      vector<char>
#define vvc     vector<vc>
#define vb      	vector<bool>
#define vvb     	vector<vb>
#define print(a,i)	for(auto i:a){cout<<i<<" ";}cout<<endl

bool Solve(int n,string ans){
    if(ans.size()==3){if(n==0)return true; return false;}
    if(n>27)return false;
    bool s=false;
    F(1,26,1,i){
        if(i<=n){
            char c='a'+i-1;
            s=Solve(n-i,ans+c);
        }
        if(s)return s;
    }
    return false;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int t=5;
	cin>>t;
	while(t--){
        int n;cin>>n;
        string ans="";
        Solve(n,ans);
        cout<<ans<<endl;
	}
	return 0;
}