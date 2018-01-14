#include <stdio.h>
#include <algorithm>
using namespace std;
int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);
	int mn = 9999;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (k % a != 0)
			continue;
		mn = min(mn, k / a);
	} 
	printf("%d", mn);
}
