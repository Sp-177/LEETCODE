#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<ll> hash1, hash2, power;
    ll prime = 31, mod = 1e9 + 7;
    vector<vector<ll>> dp;

    ll fexp(ll b, ll po) {
        ll res = 1;
        while (po) {
            if (po & 1) res = (res * b) % mod;
            b = (b * b) % mod;
            po >>= 1;
        }
        return res;
    }

    ll getHash(ll i, ll j, bool forward, ll n) {
        ll res = 0, pv = 0;
        if (forward) {
            res = hash1[j];
            if (i > 0) pv = hash1[i - 1];
            res = (res - pv + mod) % mod;
            res = (res * fexp(power[i], mod - 2)) % mod;
        } else {
            res = hash2[i];
            if (j + 1 < n) pv = hash2[j + 1];
            res = (res - pv + mod) % mod;
            res = (res * fexp(power[n - j - 1], mod - 2)) % mod;
        }
        return res;
    }

    bool isPalindrome(string &s, ll i, ll j, ll n) {
        ll len = j - i + 1;
        ll h1 = getHash(i, j, true, n);
        ll h2 = getHash(i, j, false, n);
        return h1 == h2;
    }

    ll solve(string &s, ll i, ll j, ll n) {
        if (i >= j || isPalindrome(s, i, j, n)) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        ll ans = LLONG_MAX;
        for (ll k = i; k < j; ++k) {
            if (isPalindrome(s, i, k, n)) {
                ans = min(ans, 1 + solve(s, k + 1, j, n));
            }
        }
        return dp[i][j] = ans;
    }

    int minCut(string s) {
        ll n = s.size();
        hash1.resize(n, 0);
        hash2.resize(n, 0);
        power.resize(n + 1, 1);

        for (ll i = 1; i <= n; ++i)
            power[i] = (power[i - 1] * prime) % mod;

        for (ll i = 0; i < n; ++i) {
            ll num = s[i] - 'a' + 1;
            if (i > 0) hash1[i] = hash1[i - 1];
            hash1[i] = (hash1[i] + num * power[i]) % mod;
        }

        for (ll i = n - 1; i >= 0; --i) {
            ll num = s[i] - 'a' + 1;
            if (i + 1 < n) hash2[i] = hash2[i + 1];
            hash2[i] = (hash2[i] + num * power[n - i - 1]) % mod;
        }

        dp.assign(n, vector<ll>(n, -1));
        return solve(s, 0, n - 1, n);
    }
};
