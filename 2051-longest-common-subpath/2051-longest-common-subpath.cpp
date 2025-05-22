#define ll long long
const ll P = 1e5 + 7, M1 = 1e9 + 7, M2 = 1e9 + 9, M3 = 1e9 + 33;
const int MAXN = 1e5 + 10;

ll fexp(ll base, ll power, ll M) {
    ll res = 1;
    while (power) {
        if (power & 1) res = res * base % M;
        base = base * base % M;
        power >>= 1;
    }
    return res;
}

// Precomputed powers and inv powers
vector<ll> pow1(MAXN), inv1(MAXN), pow2(MAXN), inv2(MAXN), pow3(MAXN), inv3(MAXN);

void precompute() {
    pow1[0] = pow2[0] = pow3[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        pow1[i] = pow1[i - 1] * P % M1;
        pow2[i] = pow2[i - 1] * P % M2;
        pow3[i] = pow3[i - 1] * P % M3;
    }
    inv1[0] = inv2[0] = inv3[0] = 1;
    ll invP1 = fexp(P, M1 - 2, M1);
    ll invP2 = fexp(P, M2 - 2, M2);
    ll invP3 = fexp(P, M3 - 2, M3);
    for (int i = 1; i < MAXN; i++) {
        inv1[i] = inv1[i - 1] * invP1 % M1;
        inv2[i] = inv2[i - 1] * invP2 % M2;
        inv3[i] = inv3[i - 1] * invP3 % M3;
    }
}

// Custom struct for triple hash
struct TripleHash {
    ll h1, h2, h3;
    bool operator==(const TripleHash& other) const {
        return h1 == other.h1 && h2 == other.h2 && h3 == other.h3;
    }
};

// Custom hash function for unordered_map
struct HashFunc {
    size_t operator()(const TripleHash& x) const {
        return hash<ll>()(x.h1) ^ hash<ll>()(x.h2 << 1) ^ hash<ll>()(x.h3 << 2);
    }
};

class Hasher {
    vector<ll> h1, h2, h3;
public:
    Hasher(const vector<int>& arr) {
        int n = arr.size();
        h1.resize(n), h2.resize(n), h3.resize(n);
        for (int i = 0; i < n; i++) {
            ll val = arr[i] + 1;
            h1[i] = ((i ? h1[i - 1] : 0) + val * pow1[i] % M1) % M1;
            h2[i] = ((i ? h2[i - 1] : 0) + val * pow2[i] % M2) % M2;
            h3[i] = ((i ? h3[i - 1] : 0) + val * pow3[i] % M3) % M3;
        }
    }

    TripleHash get_hash(int l, int r) {
        ll a = h1[r] - (l ? h1[l - 1] : 0);
        ll b = h2[r] - (l ? h2[l - 1] : 0);
        ll c = h3[r] - (l ? h3[l - 1] : 0);
        a = (a + M1) * inv1[l] % M1;
        b = (b + M2) * inv2[l] % M2;
        c = (c + M3) * inv3[l] % M3;
        return {a, b, c};
    }
};

class Solution {
public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        precompute();
        int m = paths.size();
        vector<Hasher> hashers;
        int minLen = INT_MAX;
        for (auto& path : paths) {
            hashers.emplace_back(path);
            minLen = min(minLen, (int)path.size());
        }

        auto isValid = [&](int len) {
            unordered_map<TripleHash, int, HashFunc> freq;
            for (int i = 0; i < m; i++) {
                unordered_set<TripleHash, HashFunc> seen;
                for (int j = len-1; j < paths[i].size(); j++) {
                    auto h = hashers[i].get_hash(j-len+1, j );
                    if (seen.insert(h).second)
                        freq[h]++;
                }
            }
            for (auto& [k, v] : freq)
                if (v == m) return true;
            return false;
        };

        int low = 1, high = minLen, ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isValid(mid)) {
                ans = mid;
                low = mid + 1;
            } else high = mid - 1;
        }
        return ans;
    }
};
