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
int a[200004];
int main(void) {
	ll sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	ll sum1 = 0;
	for (int i = 0; i < n; i++) {
		sum1 += a[i];
		if (2 * sum1 >= sum) {
			printf("%d", i + 1);
			return 0;
		}
	}
}
