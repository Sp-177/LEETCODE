#define ll 		    long long
#define ull 	    unsigned long long
#define ld		    long double
#define db		    double
#define fs		    first
#define sec 	    second
#define pb 		    push_back
#define pu 		    push
#define ins         insert
#define all(x)		x.begin(),x.end()
#define po      	pop()
#define pob     	pop_back()
#define pof     	pop_front()
#define pf      	push_front
#define fr		    front()
#define ba		    back()
#define fi(x,i) 	x.find(i)!=x.end()
#define emp       	empty()
#define sz		size()
#define pa          pair
#define pi          pa<int,int>
#define vec	        vector
#define vi		    vec<int>
#define vpi		    vec<pi>
#define vvi		    vec<vi>
#define vs		    vec<string>
#define vl		vec<ll>
#define vc      	vec<char>
#define vb      	vec<bool>
#define dq          dequeue
#define mc		map<char,int>
#define mi		map<int,int>
#define mpi		map<pi,int>
#define um          unordered_map
#define umi		    um<int,int>
#define umc 		um<char,int>
#define ums		    um<string,int>
#define si		set<int>
#define spi		set<pi>
#define sc		set<char>
#define sv		set<vi>
#define us          unordered_set
#define usi 		us<int>
#define usc		    us<char>
#define uss		    us<string>
#define pq          priority_queue
#define que_max		pq<int>
#define que_min		pq<int,vi,greater<int>>
#define que         pq<pi,vpi>
#define que_get	    pq<pq,vpi,greater<pi>>
#define inp(x)	for(int i=0;i<x.size();i++){cin>>x[i];}
#define F(x,y,z,i)	for(int i=x;i<y;i=i+z)
#define Fr(x,y,z,i)	for(int i=x;i>y;i=i-z)
#define Fa(x,i)		for(auto i:x)
#define pr(a)		for(auto i:a){cout<<i<<" ";}cout<<endl
#define ppr(a,x)		for(auto i:a){cout<<i.x<<" ";}cout<<endl
#define pp(a)  		for(auto i:a){for(auto j:i){cout<<j<<' ';}cout<<endl;}cout<<endl
#define lb(x,i)        	lower_bound(all(x),i)
#define ub(x,i)      	upper_bound(all(x),i)



class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
       if(k==1)return nums;
       
       int i=0,j=0;
       int n=nums.sz;
       int maxi=0;
       int l=0;vi ans(n-k+1,-1);
       while(j<n&&i<=n-k){
        if(maxi+1==nums[j]||i==j){maxi=nums[j];}
        else maxi=-1;
        if(j-i+1==k||maxi==-1){
            ans[l++]=maxi;
            i++;
            if(maxi==-1){
                while(i<j&&i<=n-k){ans[l++]=-1;i++;}
                maxi=nums[j];
                i=j;
            }
        }
        j++;
       }
       return ans; 
    }
};