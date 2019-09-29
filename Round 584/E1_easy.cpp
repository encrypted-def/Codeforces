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
 
int t;
int a[4][100];
int n,m;
int min4(int a, int b, int c, int d){
  return min(min(a,b),min(c,d));
}
int max4(int a, int b, int c, int d){
  return max(max(a,b),max(c,d));
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed;
  cout.precision(20);
///////////////////////////////////////////////
  sf1(t);
  while(t--){
    rep(i,0,4) rep(j,0,100) a[i][j] = 0;
    sf2(n,m);
    rep(i,0,n) rep(j,0,m) sf1(a[i][j]);
    if(n==1){
      int tot = 0;
      rep(i,0,m) tot = max(tot,a[0][i]);
      pf1l(tot);
      continue;
    }
    if(n==2){
      int mx1=0;
      int mx2=0;
      rep(i,0,n)rep(j,0,m){
        if(a[i][j]>mx1){
          mx2=mx1;
          mx1=a[i][j];
        }
        else if(a[i][j]>mx2) mx2=a[i][j];
      }
      pf1l(mx1+mx2);
      continue;
    }
    if(n==3){
      int mx1=0;
      int mx2=0;
      int mx3=0;
      rep(i,0,n)rep(j,0,m){
        if(a[i][j]>mx1){
          mx3=mx2;
          mx2=mx1;
          mx1=a[i][j];
        }
        else if(a[i][j]>mx2){
          mx3=mx2;
          mx2=a[i][j];
        }
        else if(a[i][j]>mx3)
          mx3=a[i][j];
      }
      pf1l(mx1+mx2+mx3);
      continue;
    }
    vector<pii> tmp1;
    rep(i,0,n) rep(j,0,m) tmp1.pb({a[i][j],j});
    sort(all(tmp1),greater<pii>());
    if(tmp1.size() > 13) tmp1.erase(tmp1.begin()+13,tmp1.end());
    vector<pii> tmp2;
    rep(j,0,m){
      tmp2.pb({a[0][j]+a[1][j],j});
      tmp2.pb({a[1][j]+a[2][j],j});
      tmp2.pb({a[2][j]+a[3][j],j});
      tmp2.pb({a[3][j]+a[0][j],j});      
    }
    sort(all(tmp2),greater<pii>());
    if(tmp2.size() > 13) tmp2.erase(tmp2.begin()+13,tmp2.end());
    vector<pii> tmp3;
    rep(j,0,m){
      tmp3.pb({a[0][j]+a[2][j],j});
      tmp3.pb({a[1][j]+a[3][j],j});
    }
    sort(all(tmp3),greater<pii>());
    if(tmp3.size() > 13) tmp3.erase(tmp3.begin()+13,tmp3.end());
    
    vector<pii> tmp4;
    rep(j,0,m){
      tmp4.pb({a[0][j]+a[1][j]+a[2][j],j});
      tmp4.pb({a[1][j]+a[2][j]+a[3][j],j});
      tmp4.pb({a[2][j]+a[3][j]+a[0][j],j});
      tmp4.pb({a[3][j]+a[0][j]+a[1][j],j});      
    }
    sort(all(tmp4),greater<pii>());
    if(tmp4.size() > 13) tmp4.erase(tmp4.begin()+13,tmp4.end());
 
    vector<pii> tmp5;
    rep(j,0,m){
      tmp5.pb({a[0][j]+a[1][j]+a[2][j]+a[3][j],j});
    }
    sort(all(tmp5),greater<pii>());
    if(tmp5.size() > 13) tmp5.erase(tmp5.begin()+13,tmp5.end());
 
    int ans = tmp5[0].X;
    // 3+1
    for(int i = 0; i < min(13,sz(tmp4)); i++){
      int avoid = tmp4[i].Y;
      for(int j = 0; j < m; j++){
        if(j==avoid) continue;
        ans = max(ans,tmp4[i].X+max4(a[0][j],a[1][j],a[2][j],a[3][j]));
      }
    }
    // 2+1+1(tmp3)
    for(int i = 0; i < min(13,sz(tmp3)); i++){
      int avoid = tmp3[i].Y;
      int mx1=0,mx2=0;
      for(int j = 0; j < m; j++){
        if(j==avoid) continue;
        int val = max4(a[0][j],a[1][j],a[2][j],a[3][j]);
        if(val > mx1){
          mx2=mx1;
          mx1=val;
        }
        else if(val > mx2){
          mx2=val;
        }
      }
      ans = max(ans,tmp3[i].X+mx1+mx2);
    }
    // 2+1+1(tmp2)
    for(int i = 0; i < min(13,sz(tmp2)); i++){
      int avoid = tmp2[i].Y;
      int mx1=0,mx2=0;
      for(int j = 0; j < m; j++){
        if(j==avoid) continue;
        int val = max4(a[0][j],a[1][j],a[2][j],a[3][j]);
        if(val > mx1){
          mx2=mx1;
          mx1=val;
        }
        else if(val > mx2){
          mx2=val;
        }
      }
      ans = max(ans,tmp2[i].X+mx1+mx2);
    }
 
    // 2+2(tmp3)
    for(int i = 0; i < sz(tmp3); i++){
      for(int j = i+1; j < sz(tmp3); j++){
        if(tmp3[i].Y != tmp3[j].Y) ans = max(ans,tmp3[i].X+tmp3[j].X);
      }
    }
 
 
    // 2+2(tmp2)
    for(int i = 0; i < sz(tmp2); i++){
      for(int j = i+1; j < sz(tmp2); j++){
        if(tmp2[i].Y != tmp2[j].Y) ans = max(ans,tmp2[i].X+tmp2[j].X);
      }
    }
 
    // 1+1+1+1
    for(int i = 0; i < sz(tmp1); i++){
      for(int j = i+1; j < sz(tmp1); j++){
        if(tmp1[i].Y == tmp1[j].Y) continue;
        for(int k = j+1; k < sz(tmp1); k++){
          if(tmp1[i].Y == tmp1[k].Y) continue;
          if(tmp1[j].Y == tmp1[k].Y) continue;
          for(int l = k+1; l < sz(tmp1); l++){
            if(tmp1[i].Y == tmp1[l].Y) continue;
            if(tmp1[j].Y == tmp1[l].Y) continue;
            if(tmp1[k].Y == tmp1[l].Y) continue;
            ans = max(ans,tmp1[i].X+tmp1[j].X+tmp1[k].X+tmp1[l].X);
          }
        }
      }
    }
    pf1l(ans);
  }
}
