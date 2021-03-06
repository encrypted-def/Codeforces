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
const int INF = 0x3f7f7f7f;
const ll INF_LL = 0x77f7f7f7f7f7f7f;
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

ll D[5001][5001]; // D[i][j] : i번째 hill까지에서 j개 택할 때 최솟값.(i 반드시 포함)
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	sf1(N);
	vl A(N + 3), C(N + 3);
	A[0] = -INF_LL;
	A[N + 1] = -INF_LL;
	rep(i, 1, N + 1) rep(j, 1, N + 1) D[i][j] = INF_LL;
	rep(i, 1, N+1) sf1(A[i]);
	ll mn = INF_LL;
	rep(i, 1, N + 1) {
		D[i][1] = max(0ll, A[i + 1] - A[i] + 1) + max(0ll, A[i - 1] - A[i] + 1);
		C[i] = D[i][1];
		if (mn > C[i]) mn = C[i];
	}
	pf1(mn);
	rep(select, 2, (N + 1) / 2 + 1) {
		ll accu = INF_LL;
		bool fi = true;
		ll mn = INF_LL;
		rep(i, 1, N+1) {
			if ((i + 1) / 2 < select) continue;
			if (fi) {				
				fi = false;
				// A[i-1]을 A[i-2]-1로 만들어놓은 상태
				D[i][select] = D[i - 2][select-1] + max(0ll, min(A[i-1],(A[i - 2] - 1)) - A[i] + 1) + max(0ll,A[i+1]-A[i]+1);
				rep(j, 1, i - 1) {
					accu = min(accu, D[j][select - 1]);
				}
				mn = D[i][select];
				continue;
			}
			D[i][select] = accu + C[i] ; // i-3 이전에 이미 select-1개를 뽑아놓은 상황
			ll val = D[i - 2][select - 1] + max(0ll, min(A[i - 1], (A[i - 2] - 1)) - A[i] + 1) + max(0ll, A[i+1]-A[i]+1);
			if (val < D[i][select])
				D[i][select] = val;
			if (accu > D[i - 2][select - 1])
				accu = D[i - 2][select - 1];
			if (mn > D[i][select])
				mn = D[i][select];
			
		}
		pf1(mn);
	}
}
