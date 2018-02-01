#include <stdio.h>
#include <algorithm>
using namespace std;
bool isPerfect(int n) {
	int ans = 0;
	while (n > 0) {
		ans += n % 10;
		n /= 10;
	}
	return 10 == ans;
}
int main(void) {
	int k;
	scanf("%d", &k);
	for (int i = 1; ; i++) {
		if (isPerfect(i))
			k--;
		if (k == 0) {
			printf("%d", i);
			return 0;
		}
	}
	return 0;
}
