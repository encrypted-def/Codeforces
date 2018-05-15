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
int main(void) {
	int k, n, s, p;
	scanf("%d %d %d %d", &k, &n, &s, &p);
	int tmp1 = (n + s - 1) / s;
	printf("%d", (k*tmp1 + p - 1) / p);
}
