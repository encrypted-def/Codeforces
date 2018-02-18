#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
#include <math.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

int isSquare(int x) {
	if (x == 1)
		return 1;
	if (x == 2 || x == 3)
		return -1;
	if (x == 4)
		return 2;
	int t = sqrt(x);
	for (int i = t - 1; i <= t + 1; i++)
		if (i*i == x)
			return i;
	return -1;
}
int main(void) {
	int t;
	scanf("%d", &t);
	while (t--) {
		int x;
		scanf("%d", &x);
		if (x == 0) {
			printf("1 1\n");
			continue;
		}
		if (x == 1 || x == 2) {
			printf("-1\n");
			continue;
		}
		if (x == 3) {
			printf("2 2\n");
			continue;
		}
		bool isEx = false;
		for (int cand_n = 1; cand_n*cand_n <= 2 * x; cand_n++) {
			if (cand_n*cand_n < x)
				continue;
			int zerostate = cand_n*cand_n - x;
			if (zerostate == 0)
				continue;
			int quad = isSquare(zerostate);
			if (quad == -1) // n / m = quad가 되어야 함
				continue;
			int cand_m = cand_n / quad;
			if (cand_n / cand_m == quad) {
				isEx = true;
				printf("%d %d\n", cand_n, cand_m);
				break;
			}
		}
		if (!isEx)
			printf("-1\n");
	}
}
