#define ll long long
const ll P=1e5+7,M=1e9+7;
ll fexp(ll b,ll p){
    ll r=1LL;
    while(p>0){
        if(p&1)r*=b;
        r%=M;
        p>>=1;
        b*=b;
        b%=M;
    }
    return r;
}
class HT{
    public:
    vector<ll>htable;
    HT(string &word){
        build(word);
    }
    int lhp(){
        ll n=htable.size(),i=n-2,j=1;
        while(i>=0){
        ll h1=hash(0,i);
        ll h2=hash(j,n-1);
        if(h1==h2)break;
        i--;
        j++;
        }
        return i+1;
        
    }
    private:
    void build(string&word){
        ll n=word.size();
        htable.resize(n,0);
        for(ll i=0;i<n;i++){
            ll p=0;
            if(i>0)p=htable[i-1];
            ll num=word[i]-'a'+1;
            htable[i]=(p+(num*fexp(P,i))%M)%M;
        }
    }
    ll hash(ll l,ll r){
        ll p=0;
        if(l>0)p=htable[l-1];
        ll c=(htable[r]-p+M)%M;
        ll res=(c*(fexp((fexp(P,l))%M,M-2))%M)%M;
        return res%M;
    }
};
class Solution {
public:
    string longestPrefix(string s) {
        HT obj(s);
        return s.substr(0,obj.lhp());
    }
};