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
#define F(x,y,z)	for(int i=x;i<y;i=i+z)
#define Fa(x)		for(auto a:x)
#define vvi		vector<vi>
#define vc      vector<char>
#define vvc     vector<vc>
#define vb      	vector<bool>
#define vvb     	vector<vb>
#define print(a)	for(auto i:a){cout<<i<<" ";}cout<<endl
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vs t=strs;
       int j=0;
       F(0,t.size(),1){
           sort(all(t[j]));
           j++;
           
       }
       unordered_map<string,vi>m;
       j=0;
       F(0,t.size(),1){m[t[j]].push_back(j);
       j++;}
       vector<vs> ans;
       Fa(m){
           vs o;
           int j=0;
        //    cout<<a.f<<endl;
           F(0,a.s.size(),1){
               o.pb(strs[a.s[j]]);
               j++;
           }
           ans.pb(o);
       }
       sort(all(ans));
       return ans;
    }
};