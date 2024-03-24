#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll 		long long
#define f 		first
#define sec 		second
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
#define u_sc		unordered_set<char>
#define u_ss		unordered_set<string>
#define ld		long double
#define d		double
#define all(x)		x.begin(),x.end()
#define que_max		priority_queue<int>
#define que_min		priority_queue<int,vi,greater<int>>
#define F(x,y,z,i)	for(int i=x;i<y;i=i+z)
#define Fr(x,y,z,i)	for(int i=x;i>y;i=i-z)
#define Fa(x,i)		for(auto i:x)
#define vvi		vector<vi>
#define vc      vector<char>
#define vvc     vector<vc>
#define vll		vector<ll>
#define vb      	vector<bool>
#define vvb     	vector<vb>
#define print(a,i)	for(auto i:a){cout<<i<<" ";}cout<<endl

long mod = 1000000007;

long power(long a, long b) {
        long res = 1;
        while (b > 0) {
            if ((b & 1) == 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
}

void Solve(){

}


class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        vll ans(nums.size(),0);
        unordered_map<int,ll> m;
        priority_queue<pair<ll,int>> q;
        F(0,nums.size(),1,i){
            m[nums[i]]+=freq[i];
            q.push({m[nums[i]],nums[i]});
            while(!q.empty()){
                if(m[q.top().sec]!=q.top().f){
                    int x=q.top().sec;
                    q.pop();
                    q.push({m[x],x});
                }
                else break;
            }
            ans[i]=q.top().f;
            }
        return ans;
        }
                
    };