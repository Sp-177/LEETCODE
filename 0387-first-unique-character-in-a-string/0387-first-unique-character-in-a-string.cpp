class Solution {
public:
    
#define ll 		long long
#define f 		first
#define s 		second
#define pb 		push_back
#define p 		push
#define vi		vector<int>
#define pii 		pair<int,int>
#define vpi		vector<pii>
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
#define print(a)	for(auto i:a){cout<<i<<" ";}cout<<endl

    int firstUniqChar(string s) {
        u_mc m;
        Fa(s)m[i]++;
        F(0,s.size(),1)if(m[s[i]]==1)return i;
        return -1;
    }
};