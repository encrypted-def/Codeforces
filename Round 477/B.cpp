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
ll n, A, B;
ll s[100005];
ll firsthole = 0;
ll tot = 0;
int main(void) {
	scanf("%lld %lld %lld", &n, &A, &B);
	scanf("%lld", &firsthole);
	tot += firsthole;
	for (int i = 0; i < n - 1; i++) {
		scanf("%lld", &s[i]);
		tot += s[i];
	}
	sort(s, s + n - 1);
	int cnt = 0;
	while (firsthole*A < tot*B) {
		cnt++;
		tot -= s[n - 1 - cnt];
	}
	printf("%d", cnt);
}
