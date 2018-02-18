#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
int p[1000007];
int main(void) {
	scanf("%d", &n);
	int mx = 0;
	int t;
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		mx = max(mx, min(t - 1, 1000000-t));
	}
	printf("%d", mx);	
}
