#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
using ll = long long;
using ul = unsigned long;
using ull = unsigned long long;

const int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

// #define CUST_PAIR
// #define BST
#define mp make_pair
#define mt make_tuple
#define nl puts("")
#define pb push_back
#define fst(v) (*v.cbegin())
#define lst(v) (*v.crbegin())
#define tint(s, i) (s[i] - '0')
#define cint(i) (i + '0')
#define tchar(s, i) (s[i] - 'a')
#define FA(i, v) for (auto& i : (v))
#define F(i, a, b) for (int i = a; i < b; ++i)
#define FE(i, a, b) for (int i = a; i <= b; ++i)
#define FG(i, a, b) for (int i = a; i > b; --i)
#define FGE(i, a, b) for (int i = a; i >= b; --i)
#define tr(it, x, ed) for (auto it = (x).begin(), ed = (x).end(); it != ed; ++it)
#define eq(a, b) (!(a ^ b))
#define sz(x) ((int)((x).size()))
#define lbit(x) ((x & (-x))) // get lowest bit
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define mid(l, r) (l + ((r - l) >> 1))
#define lft(l) (l << 1)
#define rht(r) ((r << 1) + 1)
#define has(v, ele) (v.find(ele) != v.end())
template<typename... args>
void dbg(args... arg) {
	__attribute__((unused)) auto _ = {((void)(cout << arg << "  "), 0)...};
	nl;
}
#define chq printf("%s\n", "current line is ok...")
#define scan(d) scanf("%lld", &d)
#define scan2(c, d) scanf("%d%d", &c, &d)
#define scans(s) scanf("%s", s)
#define initd(d) memset(d, 0, sizeof(d))
#define loc(v, ele) lower_bound(v.cbegin(), v.cend(), ele) - v.cbegin()
#define qnav do { \
    freopen("/home/drac/Documents/CP/input.txt", "r", stdin); \
    setbuf(stdout, NULL); \
    freopen("/home/drac/Documents/CP/output.txt", "w", stdout); \
} while (0)

const int MAXN = (int)1e6;
const ll MOD = 1000000007;

#ifdef CUST_PAIR
template <typename T>
inline void hash_combine(std::size_t &seed, const T &val) {
    seed ^= hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
// auxiliary generic functions to create a hash value using a seed
template <typename T> inline void hash_val(size_t &seed, const T &val) {
    hash_combine(seed, val);
}
template <typename T, typename... Types>
inline void hash_val(size_t &seed, const T &val, const Types &... args) {
    hash_combine(seed, val);
    hash_val(seed, args...);
}

template <typename... Types>
inline size_t hash_val(const Types &... args) {
    size_t seed = 0;
    hash_val(seed, args...);
    return seed;
}

struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const {
        return hash_val(p.first, p.second);
    }
};

struct pair_comp {
    inline bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
        return a.first < b.first && a.second < b.second;
    }
};
#endif

#ifdef BST
typedef struct treenode {
	struct treenode* left;
	struct treenode* right;
	int val;
} node;

node nd[SIZE];
queue<node*> q;

void init() {
	F(i, 0, SIZE) q.push(&nd[i]);
}

node* newnode(int val = -1) {
	node* cur = q.front(); q.pop();
	cur->left = cur->right = nullptr;
	cur->val = val;
	return cur;
}
#endif

ll fact[MAXN];

ull binp(ull x, ull y) {
	x %= MOD;
	ull res = 1;
	while (y) {
		if (y & 1) res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}

void init() {
	fact[0] = fact[1] = 1;
	for (int i = 2; i < MAXN; ++i) fact[i] = i * fact[i - 1] % MOD;
}

/*
	nCr = n! * (inv(r!) % m) * (inv((n - r)!) % m)
	since m is prime, thus a^m-2 % m = inv(a) % m
*/
ll ncr(ll n, ll r) {
	return fact[n] * binp(fact[r], MOD - 2) % MOD * binp(fact[n - r], MOD - 2) % MOD;
}

int main() {
    //qnav;
    init();
    ll n, t; scan(n);
    for (ll c = 1; c <= n; ++c) {
    	scan(t);
    	ll res = 1, prefix, k; scan(prefix);
    	/*
		given that last job must finish at last, thus the last time slot is fixed.
		Hence the problem reduces to finding 
			C(k1 - 1, k1 - 1) * ∏i∈[2,n] C(k1 + ... + ki - 1, ki - 1)
    	*/ 
    	for (int i = 1; i < t; ++i) {
    		scan(k);
    		prefix += k;
    		res = res * ncr(prefix - 1, k - 1) % MOD;
    	}
    	cout << "Case " << c << ": " << res, nl;
    }
    return 0;
}
