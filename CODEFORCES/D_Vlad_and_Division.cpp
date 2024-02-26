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

void Solve(){

}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int t=5;
	cin>>t;
	F(0,t,1,k){
        int n;
        int ans=0;
        vi v;
        F(0,n,1,i)cin>>v[i];
        int check=(1<<32) -1;
        cout<<check<<endl;
        u_si S;
        F(0,n,1,i){
            F(0,n,1,j){
                if(S.find(i)==S.end()&&S.find(j)==S.end()&&v[i]^v[j]==check)
                {
                    S.insert(i);
                    S.insert(j);
                    ans++;
                    break;
                }
            }
            if(S.find(i)==S.end())ans++;
       }
        cout<<ans<<endl;
        
	}
	return 0;
}