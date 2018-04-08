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
int n;
ll A[1005];
ll B[1005];
ll diff[1005];
int k1, k2;
int main(void) {
	scanf("%d %d %d", &n, &k1, &k2);
	for (int i = 0; i < n; i++)
		scanf("%lld", &A[i]);
	for (int i = 0; i < n; i++)
		scanf("%lld", &B[i]);
	for (int i = 0; i < n; i++)
		diff[i] = abs(A[i] - B[i]);
	int k = k1 + k2;
	while (k--) {
		sort(diff, diff + n);
		diff[n - 1] = abs(diff[n-1]-1);
	}
	ll sum = 0;
	for (int i = 0; i < n; i++)
		sum += diff[i] * diff[i];
	printf("%lld", sum);
}
