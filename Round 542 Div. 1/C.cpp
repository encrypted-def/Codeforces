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

int l[6000000],r[6000000];
int d[3005][3005];
int mod = 1e9+7;
int idx = 0;
int ans[3005];
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed;
  cout.precision(20);
///////////////////////////////////////////////
  fill(l,l+6000000,-1);
  fill(r,r+6000000,-1);  
  int m;
  sf1(m);
  vi s(m);
  rep(i,0,m){
    sf1(s[i]);
  }
  rep(i,0,m){    
    d[i][i] = 1;
    rep(j,i+1,m){
      for(int k = j-1; k >= j-4; k--){
        if(k < i){
          if(k==j-4){
            int tmp = ((s[k+1]) << 3)+((s[k+2]) << 2)+((s[k+3]) << 1)+((s[k+4]));
            if(tmp == 3 or tmp==5 or tmp==14 or tmp==15) break;
            d[i][j] += 1;
            break;
          }
          else{
            d[i][j] += 1;
            break;
          }
        }
        if(k == j-4){
          int tmp = ((s[k+1]) << 3)+((s[k+2]) << 2)+((s[k+3]) << 1)+((s[k+4]));
          //cout << "sdsff " << tmp << '\n';
          if(tmp == 3 or tmp==5 or tmp==14 or tmp==15) continue;          
        }
        d[i][j] = (d[i][j]+d[i][k])%mod;
      }
    }
  }
  rep(i,0,m){
    rep(j,i+1,m){
      //cout << i << ' ' << j << ' ' << d[i][j] << '\n';
    }
  }
  rep(i,0,m){
    int cur = 0;
    int dup = 0; // duplicate
    for(int j = i; j >= 0; j--){
      if(s[j] == 0){
        if(l[cur] == -1){
          idx++;
          l[cur] = idx;
          cur = idx;
        }
        else{
          cur = l[cur];
          dup++;
        }
      }
      else{
        if(r[cur] == -1){
          idx++;
          r[cur] = idx;
          cur = idx;
        }
        else{
          cur = r[cur];
          dup++;
        }
      }
    }
    //cout << i << ' ' << dup << '\n';
    for(int k = 0; k <= i-dup; k++){
      ans[i] = (ans[i]+d[k][i])%mod;
    }
    if(i > 0) ans[i] = (ans[i]+ans[i-1])%mod;
  }    
  rep(i,0,m) pf1l(ans[i]);
}
 
