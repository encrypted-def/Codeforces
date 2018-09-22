# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
const int ddx[8] = { 0,0,1,1,1,-1,-1,-1 }, ddy[8] = { 1,-1,1,0,-1,1,0,-1 };
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

class Seg {
public:
	int N;
	vector<ll> seg;
	Seg(int _N) {
		N = _N;
		seg.resize(2*N+2);
	}
	void init() {
		for (int i = N - 1; i > 0; i--) seg[i] = GCD(seg[i << 1], seg[i << 1|1]);
	}
	void update(int i, int val) {
		for (seg[i += N] = val; i > 1; i >>= 1) seg[i >> 1] = GCD(seg[i], seg[i ^ 1]);
	}
	// sum of num[l:r+1]
	ll query(int l, int r) {
		ll ret = 0;
		for (l += N, r += N+1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ret = GCD(ret,seg[l++]);
			if (r & 1) ret = GCD(ret,seg[--r]);
		}
		return ret;
	}
};

vector<bool> sieve(4000,1);
vi prime;
map<int,int> M;
int N;
int A[300005];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
  sieve[1] = 0;
  for(int p = 2; p <= 3999; p++){
    if(!sieve[p]) continue;
    prime.pb(p);
    for(int j = p*p; j <= 3999; j+=p) sieve[j] = 0;
  }
  sf1(N);
  rep(i,0,N) sf1(A[i]);
  //rep(i,0,N) A[i]=9999991;
  sort(A,A+N);
  int g = 0;
  rep(i,0,N) g = GCD(g,A[i]);
  rep(i,0,N) A[i] /= g;
  rep(i,0,N){
    int a = A[i];
    while(a>1){
      for(auto p : prime){
        if(a%p != 0) continue;
        M[p]++;
        while(a%p==0){
          a /= p;
        }
        if(a==1) break;
      }
      if(a>1){
        M[a]++;
        break;
      }
    }
  }
  int mx = 0;
  for(auto m : M){
    if(m.Y > mx) mx = m.Y;
  }
  if(mx == 0){
    pf1l(-1);
    return 0;
  } 
  else pf1l(N-mx);
}
