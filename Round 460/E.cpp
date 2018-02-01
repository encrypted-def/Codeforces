#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PAIR;
#define X first
#define Y second

// To compute x^y under modulo m
ll power(ll x, ll y, ll m)
{
	if (y == 0)
		return 1;
	ll p = power(x, y / 2, m) % m;
	p = (p * p) % m;
	return (y % 2 == 0ll) ? p : (x * p) % m;
}
ll modInverse(ll a, ll m)
{
	return power(a, m - 2, m);
}
vector<PAIR> table1; // (k^(-1) * b mod p, k)
vector<PAIR> table2; // (a^k mod p, k)

int main(void) {
	ll a, b, p, x;
	scanf("%lld %lld %lld %lld", &a, &b, &p, &x);
	for (ll i = 1; i < p; i++) {
		table1.push_back( make_pair( (modInverse(i, p)*b) % p, i ));
	}
	ll po = 1;
	for (ll i = 0; i < p-1; i++) {
		table2.push_back(make_pair(po, i));
		po = (po*a) % p;
	}
	sort(table1.begin(), table1.end());
	sort(table2.begin(), table2.end());
	int idx1 = 0;
	int idx2 = 0;
	ll cnt = 0;
	while (idx1 < table1.size() && idx2 < table2.size()) {
		if (table1[idx1].X < table2[idx2].X)
			idx1++;
		else if (table1[idx1].X > table2[idx2].X)
			idx2++;
		else {
			ll val = p * table2[idx2].Y - (p - 1)*table1[idx1].Y;
			if (val <= 0ll)
				val += p * (p - 1);
			if (val <= x) {
				cnt += 1ll + (x - val) / (p*(p - 1));
			}
			idx2++;
		}
	}
	printf("%lld", cnt);
}
