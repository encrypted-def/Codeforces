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
int n, s;
int h[105];
int m[105];
int diff(int i, int j) {
	return h[j] * 60 + m[j] - h[i] * 60 - m[i];
}
int main(void) {
	scanf("%d %d", &n, &s);
	h[0] = 0; m[0] = 0;
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &h[i], &m[i]);
	if (diff(0,1) >= s + 1) {
		printf("0 0");
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		if (diff(i-1, i) >= 2 * s + 2) {
			int ans1 = h[i - 1];
			int ans2 = m[i - 1] + s + 1;
			while (ans2 >= 60) {
				ans2 -= 60;
				ans1 += 1;
			}
			printf("%d %d", ans1, ans2);
			return 0;
		}
	}
	int ans1 = h[n];
	int ans2 = m[n] + s + 1;
	while (ans2 >= 60) {
		ans2 -= 60;
		ans1 += 1;
	}
	printf("%d %d", ans1, ans2);
	return 0;
}
