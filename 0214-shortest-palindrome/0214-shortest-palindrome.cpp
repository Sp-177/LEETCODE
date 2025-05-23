#define ll long long
const ll P = 31, M = 1e9 + 7;
ll fexp(ll b, ll p) {
    ll r = 1LL;
    while (p > 0) {
        if (p & 1)
            r *= b;
        r %= M;
        p >>= 1;
        b *= b;
        b %= M;
    }
    return r;
}
class HT {
public:
    vector<ll> ht1, ht2;
    HT(string& s) { build(s); }
    ll hash(ll l,ll r,ll dir){
        if(dir==1){
            ll prev=0;
            if(l>0)prev=ht1[l-1];
            ll cur=(ht1[r]-prev+M)%M;
            cur*=(fexp(fexp(P,l)%M,M-2))%M;
            return cur%M;
        }
        ll n=ht2.size();
        ll prev=0;
        if(r<n)prev=ht2[r+1];
        ll cur=(ht2[l]-prev+M)%M;
        cur*=(fexp(fexp(P,n-1-r)%M,M-2))%M;
        return cur%M;


    }

private:
    void build(string& s) {
        ll n = s.length();
        ht1.resize(n, 0LL);
        ht2.resize(n, 0LL);
        ll j = n - 1;
        for (ll i = 0; i < n; i++) {
            ll prev1 = 0, prev2 = 0;
            if (i > 0)
                prev1 = ht1[i - 1];
            if (j < n - 1)
                prev2 = ht2[j + 1];
            ll num1 = s[i] - 'a' + 1LL;
            ll num2 = s[j] - 'a' + 1LL;
            ll exp = fexp(P, i) % M;
            ht1[i] = (prev1 + (num1 * exp) % M) % M;
            ht2[j] = (prev2 + (num2 * exp) % M) % M;
            j--;
        }
    }
};
class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.size()==0)return "";
        ll n = s.length();
        HT obj(s);
        auto from=[&](ll i1,ll l1,ll i2,ll l2)->ll{
            ll h1=obj.hash(n-l1,i1,1);
            ll h2=obj.hash(0,l2-1,-1);
            h1*=fexp(P,l2)%M;
            h1%=M;
            return (h1+h2)%M;

        };
        ll i=0;
        for( i=0;i<=n;i++){
            ll total=i+n;
            ll half=total>>1;
            ll left=half-i;
            ll h1=from(n-1,i,0,left);
            ll h2=obj.hash(n-half,n-1,1);
            if(h1==h2)break;
        }
        string rev=s.substr(n-i);
        reverse(rev.begin(),rev.end());
        string ans=rev+s;
        return ans;
    }
};