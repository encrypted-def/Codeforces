#include <stdio.h>
#include <algorithm>
using namespace std;
bool isPS(int N) {
	if (N < 0)
		return false;
	if (N == 0)
		return true;
	int d = 2;
	while (d*d <= N) {
		while (N % d == 0) {
			if (N % (d*d) != 0)
				return false;
			N = N / d / d;
		}
		d++;
	}
	if (N == 1)
		return true;
	else
		return false;
}
int main(void) {
	int n;
	scanf("%d", &n);
	int mx = -0x3f3f3f3f;
	while (n--) {
		int a;
		scanf("%d", &a);
		if (!isPS(a))
			mx = max(mx, a);
	}
	printf("%d", mx);
}
