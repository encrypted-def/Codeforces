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

typedef unsigned long long ull;
typedef unsigned int uint;
class RabinKarp{
public:
  string s;
  vector<ull> hash;
  vector<uint> pow1,pow2,powinv1,powinv2;
  uint m1 = 2123456801; // prime
  uint p1 = 11341; // primitive root.(11341(inv : 1101329063) is also primitive root)
  uint pinv1 = 1101329063; // p1*pinv1 = 1 mod m1
  uint m2 = 1987654313;
  uint p2 = 61523; //primitive root.(61523(inv : 1778430944) is also primitive root)
  uint pinv2 = 1778430944; // p2*pinv2 = 1 mod m2
  uint c2i(char c){ // c2i(??) != 0 for all characters. (To prevent hash('??') = hash('??|??')) 
    static int randomize = rand()%100;
    return randomize+c;
  }
  RabinKarp(string s):s(s){
    int n = s.size();
    hash.resize(n+1);
    pow1.resize(n), pow2.resize(n), powinv1.resize(n), powinv2.resize(n);
    pow1[0] = pow2[0] = powinv1[0] = powinv2[0] = 1; 
    for(int i = 1; i < n; i++){
      pow1[i] = (ull)pow1[i-1] * p1 % m1;
      pow2[i] = (ull)pow2[i-1] * p2 % m2;
      powinv1[i] = (ull)powinv1[i-1] * pinv1 % m1;
      powinv2[i] = (ull)powinv2[i-1] * pinv2 % m2;
    }
    int h1 = 0, h2 = 0;
    for(int i = 1; i <= n; i++){
      h1 = (h1 + (ull)pow1[i-1] * c2i(s[i-1])) % m1;
      h2 = (h2 + (ull)pow2[i-1] * c2i(s[i-1])) % m2;
      hash[i] = ((ull)h1 << 32) | h2;
    }
  }
  // s[st to en]의 hash값 반환(0-indexed)
  ull hash_range(int st, int en){
    uint h1 = (m1 + (hash[en+1] >> 32) - (hash[st] >> 32)) % m1;
    h1 = (ull)h1 * powinv1[st] % m1;
    uint h2 = (m2 + (hash[en+1] & 0x7fffffff) - (hash[st] & 0x7fffffff)) % m2;
    h2 = (ull)h2 * powinv2[st] % m2;
    return ((ull)h1 << 32) | h2;
  }
  // 주어진 string의 hash값 반환
  ull hash_str(string& s){
    uint h1 = 0, h2 = 0;
    for(int i = s.size()-1; i >= 0; i--){
      h1 = ((ull)p1*h1 + c2i(s[i])) % m1;
      h2 = ((ull)p2*h2 + c2i(s[i])) % m2;
    }
    return ((ull)h1 << 32) | h2;
  }
};

string s,t;
int num0,num1;
int main(void) {
  string ssshake = " sdakjsld3 lkn  nkl 4nkl3kln kl nkl;3 nk l    ;''";
  int tmp = time(NULL);
  for(auto c : ssshake) tmp+=c;
  srand(tmp);
  ios::sync_with_stdio(0);
  cin.tie(0);
  sf2(s,t);
//  s = "01";
 // t = string(100000,'a');
  for(auto c : s){
    if(c=='0') num0++;
    else num1++;
  }
  RabinKarp RK(t);
  // num0*a + num1*b = len(t);
  int cnt = 0;
  for(int a = 1; num0*a < t.size(); a++){
    if((t.size()-num0*a)%num1 != 0) continue;
    int b = (t.size()-num0*a)/num1;
    ull h0=0,h1=0;
    int idx = 0;
    int possible = 1;
    for(int i = 0; i < s.size(); i++){
      if(s[i] == '0'){
        if(h0 == 0){
          h0 = RK.hash_range(idx,idx+a-1);
        }
        if(RK.hash_range(idx,idx+a-1) != h0){
          possible = 0;
          break;
        }
        idx += a;
      }
      else{
        if(h1 == 0){
          h1 = RK.hash_range(idx,idx+b-1);
        }
        if(RK.hash_range(idx,idx+b-1) != h1){
          possible = 0;
          break;
        }
        idx += b;
      }
    }
    if(a==b and h0 == h1) possible = 0;
    
    cnt += possible;
  }
  cout << cnt;

}
