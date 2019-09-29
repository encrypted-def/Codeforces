# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
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
constexpr int INF = 0x7f7f7f7f;
 
class Hopcroft {
public:
  vector<int> A, B, lev;
  vector<int> HT;
  vector<bool> used;
  vector<vector<int> > adj;
  int n, m;
  Hopcroft(int n, int m):n(n),m(m),A(n+1,-1),lev(n+1),used(n+1),adj(n+1),B(m+1,-1),HT(n+1){}
  void bfs() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
      if (!used[i]) {
        lev[i] = 0;
        q.push(i);
      }
      else lev[i] = INF;
    }
    while (!q.empty()) {
      int a = q.front();
      q.pop();
      for (auto b : adj[a]) {
        if (B[b] != -1 && lev[B[b]] == INF) {
          lev[B[b]] = lev[a] + 1;
          q.push(B[b]);
        }
      }
    }
  }
  bool dfs(int a) {
    for (int &i = HT[a]; i < adj[a].size(); ++i) {
      const int b = adj[a][i];
      if (B[b] == -1 || lev[B[b]] == lev[a] + 1 && dfs(B[b])) {
        used[a] = 1;
        A[a] = b;
        B[b] = a;
        return 1;
      }
    }
    return 0;
  }
  int solve() {
    int ret = 0;
    while (1) {
      bfs(); 
      fill(HT.begin(), HT.end(), 0);
      int flow = 0;
      for(int i = 1; i <= n; i++)
        if (!used[i] and dfs(i)) flow++;
      if (flow == 0) break;
      ret += flow;
    }
    return ret;
  }
  void pushadj(int a, int b){
    adj[a].pb(b);
  }
};
 
int x[100005];
int y[100005];
vi adj[100005];
bool vis[100005];
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed;
  cout.precision(20);
///////////////////////////////////////////////
  int n,k;
  sf2(n,k);
  rep(i,1,k+1){
    int u,v;
    sf2(u,v);
    adj[u].pb(v);
    adj[v].pb(u);
  }
  vi comp_sz;
  rep(i,1,n+1){
    if(vis[i]) continue;
    int st = i;
    queue<int> q;
    q.push(st);
    vis[st] = true;
    int num = 0;
    while(!q.empty()){
      num++;
      int cur = q.front(); q.pop();
      for(auto nxt : adj[cur]){
        if(vis[nxt]) continue;
        q.push(nxt);
        vis[nxt] = true;
      }      
    }
    comp_sz.pb(num);
  }
  sort(all(comp_sz));
  int left = k;
  for(int i = sz(comp_sz)-1; i >= 0; i--){
    if(left <= comp_sz[i]-1){
      pf1l(0);
      return 0;
    }
    left -= (comp_sz[i]-1);
  }
  pf1l(left);
}
