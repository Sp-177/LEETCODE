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
#define pa          pair
#define pi          pa<int,int>
#define vec	        vector
#define vi		    vec<int>
#define vpi		    vec<pi>
#define vvi		    vec<vi>
#define vs		    vec<string>
#define vc      	vec<char>
#define vb      	vec<bool>
#define dq          dequeue
#define um          unordered_map
#define umi		    um<int,int>
#define umc 		um<char,int>
#define ums		    um<string,int>
#define us          unordered_set
#define usi 		us<int>
#define usc		    us<char>
#define uss		    us<string>
#define pq          priority_queue
#define que_max		pq<int>
#define que_min		pq<int,vi,greater<int>>
#define que         pq<pi,vpi>
#define que_get	    pq<pq,vpi,greater<pi>>
#define F(x,y,z,i)	for(int i=x;i<y;i=i+z)
#define Fr(x,y,z,i)	for(int i=x;i>y;i=i-z)
#define Fa(x,i)		for(auto i:x)
#define pr(a)		for(auto i:a){cout<<i<<" ";}cout<<endl
#define ppr(a,x)		for(auto i:a){cout<<i.x<<" ";}cout<<endl
#define pp(a)  		for(auto i:a){for(auto j:i){cout<<j<<' ';}cout<<endl;}cout<<endl
#define lb(x,i)        	lower_bound(all(x),i)
#define ub(x,i)      	upper_bound(all(x),i)




//Binary Expo

long long power(long a, long b)
{long long mod=1e9+7;long long res = 1;while (b) {if ((b & 1) == 1)res = (res * a) % mod;a = (a * a) % mod;b=b >> 1;}return res;}

// Binary MUl

long long mul(long a, long b)
{long long mod=1e9+7;long res = 1;while (b) {if ((b & 1) == 1)res = (res + a) % mod;a = (a * 2) % mod;b=b >> 1;}return res;}

//nthRoot

long double nR(ll A, ll N)
{if(N==1)return A;if(A==1)return 1;long double xPre =rand()%10;long double eps =1e-3;long double delX=INT_MAX;long double xK;
while(delX > eps){xK = ((N - 1.0)*xPre +(double)A/pow(xPre, N-1)) / (double)N;delX = abs(xK - xPre);xPre = xK;}return xK;}

	
//xor first n numbers

int nX(int n) 
{if(n % 4 == 0)return n;if(n % 4 == 1)return 1;if(n % 4 == 2)return n + 1;return 0;} 


//Comparator Class -> sets && maps && priority queue

class Cmp{public:const bool operator()(int&a,int&b){

	if(a>b)return true;
	else if(a==b)return a>b;
	return false;
}};

// Compartor Func

static const bool cmp(int&a,int&b){

	if(a>b)return true;
	else if(a==b)return a>b;
	return false;
}

//cal nCr

long long nCr(long long n, long long r)
{if (r > n) return 0;if (r == 0 || n == r) return 1;long double res = 0;for (int i = 0; i < r; i++) {res += log(n-i) - log(i+1);}
return (long long)round(exp(res));
}

//Prime

bool isPrime(int n) 
{if (n <= 1) return false; for (int i = 2; i <= sqrt(n); i++){if(n % i == 0)return false;}return true; 
} 

//all divisors

vector<long long> nD(ll n) 
{ vector<long long>ans;for (int i=1; i<=sqrt(n); i++) { if (n%i == 0) { if (n/i == i){ans.push_back(i);}else{ans.push_back(i);ans.push_back(n/i);} }}return ans; 
} 

//BinaryString

string dB(int n)
{string ans="";for (int i = 31; i >= 0; i--){int k = n >> i;if (k & 1)ans="1"+ans;else ans="0"+ans;}reverse(ans.begin(),ans.end());return ans;}

//String to Decimal

long long sD(string s){
reverse(s.begin(),s.end());long long ans=0;long p=0;for(char i:s){if(i=='1'){long fac=pow(2,p);ans+=fac;}p++;}return ans;}


//Trie Class

class Node{
    public:
    Node* arr[26];
    bool end;
    Node(){
        end=false;
        for (int i = 0; i < 26; i++) {
            arr[i] = NULL;
        }
    }
    Node* getNode(char c){
        return arr[c-'a'];
    }
};
class Trie{
    public:
    Node*root;
    Trie(){root=new Node();}
    void insert(string s){
        Node* node=root;
        for(char i:s){
            if(node->getNode(i)==NULL){
                Node* new_node=new Node();
                node->arr[i-'a']=new_node;
            }
            node=node->getNode(i);
            
        }
        node->end=true;

    }
    bool search(string s){
        Node* node=root;
        for(char i:s){
            if(node->getNode(i)==NULL){
                return false;
            }
            node=node->getNode(i);
            
        }
        return node->end;
    }
};


//Disjoint Set

class Ds{
	public:
	vector<int>par;
	int up(int node){
		if(par[node]==node){return node;}
        return par[node]=up(par[node]);
	}
	void ds(int n1,int n2){
	int p1=up(n1);
	int p2=up(n2);
	par[n2]=p1;
	par[p2]=p1;
	}
};




//LeetCode booster

auto init=[](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return ' ';}();

class Solution {
public:
    void sol(vector<int>&rew,int i,int sum,int&ans, vvi&dp){
        ans=max(ans,sum);
        if(i>=rew.size()){return ;}
        if(dp[i][sum]!=-1){return ;}
        sol(rew,i+1,sum,ans,dp);
        if(rew[i]>sum)sol(rew,i+1,sum+rew[i],ans,dp);
        dp[i][sum]=sum;
        
    }
    int maxTotalReward(vector<int>& rew) {
        sort(all(rew));
        int ans=0;
        vvi dp(rew.size(),vi(4000,-1));
        sol(rew,0,0,ans,dp);
        
        return ans;
    }
};