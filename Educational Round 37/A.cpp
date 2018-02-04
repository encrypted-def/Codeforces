#include <stdio.h>
#include <algorithm>
using namespace std;
int main(void) {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, k;
		scanf("%d %d", &n, &k);
		int arr[205];
		for (int i = 0; i < k; i++)
			scanf("%d", &arr[i]);
		int mx = 0;
		mx = max(arr[0], n - arr[k - 1]+1);
		for (int i = 1; i < k; i++)
			mx = max(mx, (arr[i] - arr[i - 1]) / 2 + 1);
		printf("%d\n", mx);
	}
}
