#include <stdio.h>
#include <algorithm>
using namespace std;
int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	double mn = 1e9;
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		mn = min(1.0*a / b * m, mn);
	}
	printf("%.10f", mn);
}
