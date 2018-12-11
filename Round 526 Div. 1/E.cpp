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

// 반드시 기울기가 감소하는 순서로 삽입해야 함
class CHT {
 public:
  bool inc;  // 쿼리 안의 x가 증가하는가?
  CHT(bool inc) : inc(inc) {}
  deque<pair<ll, ll> > line;    // 기울기, y절편(ax+b에서 a와 b)
  long double inter(int i, int j) {  // line[i]와 line[j]의 교점의 x좌표
    return 1.00L * (line[i].Y - line[j].Y) / (line[j].X - line[i].X);
  }
  ll funcval(ll i, ll x) { return line[i].X * x + line[i].Y; }
  // ax+b 직선 삽입
  void pushline(ll a, ll b) {
    line.pb({a, b});
    int i = line.size() - 1;
    while (i > 1 and inter(i, i - 1) < inter(i - 1, i - 2)) {
      line[i - 1] = line.back();
      line.pop_back();
      i--;
    }
  }
  // x = k가 올라탈 직선의 index
  int getidx(ll k) {
    int st = 0;
    int en = line.size() - 1;
    while (st < en) {
      int mid = (st + en) / 2;
      if (k < inter(mid, mid + 1))
        en = mid;  // double
      else
        st = mid + 1;
    }
    return en;
  }
  // x = k일 때의 최솟값
  ll findval(ll k) {
    if (inc) {
      while (line.size() > 1 && funcval(0, k) > funcval(1, k)) {
        line.pop_front();
      }
      return funcval(0, k);
    }
    if (line.size() == 1) return funcval(0, k);
    return funcval(getidx(k), k);
  }
};

ll n;
tuple<ll,ll,ll> rec[1000006];
ll d[1000006];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);  
  sf1(n);
  rep(i,0,n){
    ll a,b,c;
    sf3(a,b,c);
    rec[i] = {a,b,c};
  }
  sort(rec,rec+n);
  CHT cht = CHT(1); // x가 증가하는 순
  ll x0,y0,a0;
  tie(x0,y0,a0) = rec[0];
  d[0] = x0*y0-a0;
  cht.pushline(-x0, -d[0]);
  rep(i,1,n){
    ll x,y,a;
    tie(x,y,a) = rec[i];
    ll tmp = -a+x*y - cht.findval(-y);
    d[i] = max(tmp,x*y-a);
    cht.pushline(-x,-d[i]);
  }
  pf1l(*max_element(d,d+n));
}
