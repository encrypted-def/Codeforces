#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MX = 0x7f7f7f7f;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
#define X first
#define Y second
ll n, x1, x2;
pll c[300005];
ll D1[300005]; // c[i]의 resource로 x1을 커버할 때 몇 개의 server가 자유로운가
ll D2[300005]; // c[i]의 resource로 x2를 커버할 때 몇 개의 server가 자유로운가
int main(void) {
	scanf("%lld %lld %lld", &n, &x1, &x2);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &c[i].X);
		c[i].Y = i+1;
	}
	sort(c, c + n);
	ll greedy1 = MX;
	ll greedy2 = MX;
	for (int i = n-1; i >= 0; i--) {
		if (greedy1 == MX && (n - i)*c[i].X >= x1)
			greedy1 = i;
		if (greedy2 == MX && (n - i)*c[i].X >= x2)
			greedy2 = i;
		D1[i] = (n - i) - (x1 + c[i].X - 1) / c[i].X;
		D2[i] = (n - i) - (x2 + c[i].X - 1) / c[i].X;
	}
	if (greedy1 != MX) {
		for (ll i = 0; i < greedy1; i++) {
			if (D2[i] >= n - greedy1) {
				printf("Yes\n");
				printf("%lld %lld\n", n - greedy1, greedy1 - i);
				for (ll j = greedy1; j < n; j++)
					printf("%lld ", c[j].Y);
				printf("\n");
				for (ll j = i; j < greedy1; j++)
					printf("%lld ", c[j].Y);
				return 0;
			}
		}
	}
	if (greedy2 != MX) {
		for (ll i = 0; i < greedy2; i++) {
			if (D1[i] >= n - greedy2) {
				printf("Yes\n");
				printf("%lld %lld\n", greedy2 - i,n - greedy2);
				for (ll j = i; j < greedy2; j++)
					printf("%lld ", c[j].Y);
				printf("\n");
				for (ll j = greedy2; j < n; j++)
					printf("%lld ", c[j].Y);				
				return 0;
			}
		}
	}
	printf("No");
}
