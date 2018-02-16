#include <stdio.h>
#include <algorithm>
using namespace std;
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> PAIR;
int main(void) {
	int n, m;
	ll a[60];
	ll b[60];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%lld", &b[i]);

	}
	ll mn = 0x7fffffffffffffff;
	for (int hide = 0; hide < n; hide++) {
		ll mx = -0x7fffffffffffffff;
		for (int i = 0; i < n; i++) {
			if (i == hide)
				continue;
			for (int j = 0; j < m; j++)
				mx = max(mx, a[i] * b[j]);
		}
		mn = min(mx, mn);
	}
	printf("%lld", mn);
}
