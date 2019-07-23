#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
ll mod = 998244353;
 
int n,m;
 
int c[504];
int cinv[504];
ll d[504][504];
int lo[504][504];
 
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> c[i];
    cinv[c[i]] = i;
  }
  for(int i = 1; i <= n; i++){
    lo[i][i] = c[i];
    for(int j = i+1; j <= n; j++){
      lo[i][j] = min(lo[i][j-1],c[j]);
    }
  }
  for(int i = 0; i <= n+1; i++){
    for(int j = 0; j <= n+1; j++)
      d[i][j] = 1;
  }
  for(int gap = 1; gap < n; gap++){
    for(int i = 1; i <= n-gap; i++){
      int j = i+gap;
      int u = cinv[lo[i][j]];
      ll left = 0;
      for(int k = i; k <= u; k++)
        left = (left+d[i][k-1]*d[k][u-1])%mod;
      ll right = 0;
      for(int k = u; k <= j; k++)
        right = (right+d[u+1][k]*d[k+1][j])%mod;
      d[i][j] = left*right%mod;
    }
  }
  cout << d[1][n];
}
