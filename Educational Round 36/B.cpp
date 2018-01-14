#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int main(void) {
	int n, pos, l, r;
	scanf("%d %d %d %d", &n, &pos, &l, &r);
	if (l == 1 && r == n)
		printf("0");
	else if (l == 1) {
		printf("%d", abs(r - pos) + 1);
	}
	else if (r == n) {
		printf("%d", abs(l - pos) + 1);
	}
	else
		printf("%d", min(abs(pos - l), abs(pos - r)) + r - l + 2);
}
