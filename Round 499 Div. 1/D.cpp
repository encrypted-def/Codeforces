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
	if (m == 1)   return 0;
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

int N;
int l[1000006];
int parent[1000006];
int r[1000006];
int val[1000006]; // 인풋이 안바뀌었을 때 i번째의 원래 값
int type[1000006];
int flip[1000006]; // i번째의 값이 바뀌었을 때 root의 값이 얼마인가?
int cnt = 0;
// -1 : AND, -2 : OR, -3 : XOR, -4 : NOT, 0,1 : IN
bool solve(int cur) {
	if (type[cur] >= 0)
		return val[cur] = type[cur];
	if (type[cur] == -1)
		return val[cur] = solve(l[cur]) & solve(r[cur]);
	else if (type[cur] == -2)
		return val[cur] = solve(l[cur]) | solve(r[cur]);
	else if (type[cur] == -3)
		return val[cur] = solve(l[cur]) ^ solve(r[cur]);
	else
		return val[cur] = !(solve(l[cur]));
}
bool solve2(int cur) {
	if (cur == 1)
		return flip[cur] = (val[cur] ^ 1);
	if (flip[cur] != -1)
		return flip[cur];
	int p = parent[cur];
	int child2 = l[p] + r[p] - cur; // 나의 형제
	if (type[p] == -1) { // 부모가 AND이면
		if (val[child2] == 1)
			flip[cur] = solve2(p);
		else
			flip[cur] = val[1];
		return flip[cur];
	}
	if (type[p] == -2) { // 부모가 OR이면
		if (val[child2] == 0)
			flip[cur] = solve2(p);
		else
			flip[cur] = val[1];
		return flip[cur];
	}
	if (type[p] == -3) { // XOR이면
		flip[cur] = solve2(p);
		return flip[cur];
	}
	// NOT이면
	flip[cur] = solve2(p);
	return flip[cur];
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	sf1(N);
	rep(i, 1, N + 1) {
		string tt;
		sf1(tt);
		if (tt == "IN") {
			int t;
			sf1(t);
			type[i] = t;
			val[i] = t;
			continue;
		}
		if (tt == "NOT") {
			type[i] = -4;
			int t;
			sf1(t);
			l[i] = t;
			parent[t] = i;
			continue;
		}
		if (tt == "AND") type[i] = -1;
		else if (tt == "OR") type[i] = -2;
		else type[i] = -3;
		int ll, rr;
		sf2(ll, rr);
		l[i] = ll;
		r[i] = rr;
		parent[ll] = i;
		parent[rr] = i;
	}
	solve(1);
	fill(flip, flip + N + 1, -1);
	rep(i, 1, N + 1) {
		if (type[i] < 0) continue;
		cout << solve2(i);
	}
}
