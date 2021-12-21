#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

const int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

#define mp make_pair
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
#define scan(d) scanf("%d", &d)
#define scan3(a, b, c) scanf("%d%d%d\n", &a, &b, &c)
#define scans(s) scanf("%s", s)
#define initd(d) memset(d, 0, sizeof(d))
#define loc(v, ele) lower_bound(v.cbegin(), v.cend(), ele) - v.cbegin()

const int MAXN = 10000;
const int MOD = 1000000007;

typedef vector<int> vi;
using ll = long long;
using ul = unsigned long;
using ull = unsigned long long;

struct pair_comp {
    inline bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
        return a.first < b.first && a.second < b.second;
    }
};

ull binp(ull x, ull y) {
	ull res = 1;
	while (y) {
		if (y & 1) res *= x;
		x *= x;
		y >>= 1;
	}
	return res;
}

void solve() {
    /*
	case 1: at 2 boundaries. 4 choices of first make, 3 choices of adjacent make, 
	4^(m - (1 + 2)) choices of rest makes
	case 2: at somewhere in the middle. 4 * (2m - 1 - (m - 1)) choices of middle make, 
	3^2 choices of adjacent makes, 4^(m - (2 + 2)) choices of rest makes
    */
    int m; scan(m);
    int choice_of_first_middle_make = (m << 1) - 2 - (m - 1);
    ull res = ((3 * binp(4, m - 3)) << 3) + 
    	      ((choice_of_first_middle_make * 9 * binp(4, m - 4)) << 2);
    dbg(res);
}

int main() {
    int n;
    scan(n);
    while (n--) solve();
    return 0;
}
