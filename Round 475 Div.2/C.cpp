#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
#define X first
#define Y second
const ll MOD = 1e9 + 9;
ll n, a, b, k, q, r;
char s[100005];
ll pow_(ll a, ll b) {
	if (b == 0)
		return 1;
	if (b == 1)
		return a % MOD;
	if (b % 2 == 0)
		return pow_((a*a) % MOD, b / 2) % MOD;
	return (a * pow_((a*a) % MOD, b / 2))%MOD;
}
ll inv(ll a) {
	return pow_(a, MOD - 2);
}
int main(void) {
	scanf("%lld %lld %lld %lld", &n, &a, &b, &k);
	scanf("%s", s);
	for (int i = 0; i < k; i++) {
		if (s[i] == '+')
			s[i] = 1;
		else
			s[i] = -1;
	}
	q = (n+1) / k;
	ll val = 0;
	ll x = (b*inv(a)) % MOD; // b*a^(-1)
	ll calc = pow_(a, n);
	for (int i = 0; i < k; i++) {
		val = (MOD + val + (ll)s[i] * calc) % MOD;
		calc = (calc*x) % MOD;
	}
	ll tmp_fast = 0;
	ll xk = pow_(x, k);
	if (xk == 1)
		tmp_fast = q;
	else {
		ll val1 = (MOD + pow_(xk, q) - 1) % MOD;
		ll val2 = inv(xk - 1);
		tmp_fast = (val1*val2) % MOD;
	}
	ll ans = (val * tmp_fast) % MOD;
	printf("%lld", ans);
}
