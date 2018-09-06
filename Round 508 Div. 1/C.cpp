# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")

using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef tuple<int, int, int> ti3;
typedef tuple<int, int, int, int> ti4;
typedef stack<int> si;
typedef queue<int> qi;
typedef priority_queue<int> pqi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef tuple<ll, ll, ll> tl3;
typedef tuple<ll, ll, ll, ll> tl4;
typedef stack<ll> sl;
typedef queue<ll> ql;
typedef priority_queue<ll> pql;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;

const int dx[4] = { 1,-1,0,0 };
const int dy[4] = { 0,0,1,-1 };
const int ddx[8] = { 0,0,1,1,1,-1,-1,-1 }, ddy[8] = { 1,-1,1,0,-1,1,0,-1 };
const int INF = 0x7f7f7f7f;
const ll INF_LL = 0x7f7f7f7f7f7f7f7f;
ll POW(ll a, ll b, ll MMM) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }
ll LCM(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a / GCD(a, b) * b; }
ll INV(ll a, ll m) {
	ll m0 = m, y = 0, x = 1;
	if (m == 1)	return 0;
	while (a > 1) {
		ll q = a / m;
		ll t = m;
		m = a % m, a = t;
		t = y;
		y = x - q * y;
		x = t;
	}
	if (x < 0) x += m0;
	return x;
}
pll EXGCD(ll a, ll b) {
	if (b == 0) return { 1,0 };
	auto t = EXGCD(b, a%b);
	return { t.second,t.first - t.second*(a / b) };
}
bool OOB(ll x, ll y, ll N, ll M) { return 0 > x || x >= N || 0 > y || y >= M; }
#define X first
#define Y second
#define rep(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) ((int)(a.size()))
#define sf1(a) cin >> a
#define sf2(a,b) cin >> a >> b
#define sf3(a,b,c) cin >> a >> b >> c
#define sf4(a,b,c,d) cin >> a >> b >> c >> d
#define sf5(a,b,c,d,e) cin >> a >> b >> c >> d >> e
#define sf6(a,b,c,d,e,f) cin >> a >> b >> c >> d >> e >> f
#define pf1(a) cout << (a) << ' '
#define pf2(a,b) cout << (a) << ' ' << (b) << ' '
#define pf3(a,b,c) cout << (a) << ' ' << (b) << ' '<< (c) << ' '
#define pf4(a,b,c,d) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << ' '
#define pf5(a,b,c,d,e) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << ' '<< (e) << ' '
#define pf6(a,b,c,d,e,f) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << ' '<< (e) << ' ' << (f) << ' '
#define pf0l() cout << '\n';
#define pf1l(a) cout << (a) << '\n'
#define pf2l(a,b) cout << (a) << ' ' << (b) << '\n'
#define pf3l(a,b,c) cout << (a) << ' ' << (b) << ' '<< (c) << '\n'
#define pf4l(a,b,c,d) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << '\n'
#define pf5l(a,b,c,d,e) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << ' '<< (e) << '\n'
#define pf6l(a,b,c,d,e,f) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << ' '<< (e) << ' ' << (f) << '\n'
#define pfvec(V) for(auto const &t : V) pf1(t)
#define pfvecl(V) for(auto const &t : V) pf1(t); pf0l()
map<int, int> p;
const int MOD = 1e9 + 7;
int UF_find(int x) {
	if (p[x] < 0) return x;
	return p[x] = UF_find(p[x]);
}
bool UF_union(int a, int b) {
	a = UF_find(a);
	b = UF_find(b);
	if (a == b) return false;
	if (p[b] < p[a])
		swap(a, b);
	p[a] += p[b];
	p[b] = a;
	return true;
}
int N, M, K;
ll C[500006];
tuple<ll, int, int> edge[500003];
ll pow2[500006];
int main(void) {
	ll ans = 0;
	ios::sync_with_stdio(0);
	cin.tie(0);
	sf3(N, M, K);
	rep(i, 0, N) sf1(C[i]);
	rep(i, 0, M) {
		int u, v;
		sf2(u, v);
		u--; v--;
		edge[i] = { C[u] ^ C[v],u,v };
	}
	pow2[0] = 1;
	rep(i, 1, 500000 + 1)
		pow2[i] = pow2[i - 1] * 2 % MOD;
	int val_cnt = 0; // curVal의 종류
	sort(edge, edge + M);
	int idx = 0;
	while (idx < M) {
		val_cnt++;
		p.clear();
		ll curVal = get<0>(edge[idx]);

		int idx_en = idx;
		while (idx_en < M and get<0>(edge[idx_en]) == curVal) idx_en++;
		// range : idx to idx_en-1
		rep(i, idx, idx_en) {
			int u = get<1>(edge[i]);
			int v = get<2>(edge[i]);
			if (p.find(u) == p.end()) p[u] = -1;
			if (p.find(v) == p.end()) p[v] = -1;
			UF_union(u, v);
		}
		int cnt = 0;

		for (auto elem : p)
			if (elem.Y < 0) cnt++;

		ans = (ans + pow2[cnt + N - sz(p)]) % MOD;
		idx = idx_en;
	}
	ans = (ans + (MOD + pow2[K] - val_cnt) * pow2[N]) % MOD;
	if (ans < 0) ans += MOD;
	pf1l(ans);
}
