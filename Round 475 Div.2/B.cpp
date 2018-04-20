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
ll t[1004];
int main(void) {
	ll n, A, B, C, T;
	scanf("%lld %lld %lld %lld %lld", &n, &A, &B, &C, &T);
	ll tot = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &t[i]);
		if (B >= C) // 줄어드는게 더 많을 경우 바로 확인하는게 좋음
			tot += A;
		else
			tot += A + (T - t[i])*(C - B); // T초에 읽는게 좋음
	}
	printf("%lld", tot);
}
