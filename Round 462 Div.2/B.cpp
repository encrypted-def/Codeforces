#include <stdio.h>
#include <algorithm>
using namespace std;
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> PAIR;
int main(void) {
	int k;
	scanf("%d", &k);
	if (k > 36) {
		printf("-1");
		return 0;
	}
	while (k >= 2) {
		printf("8");
		k -= 2;
	}
	if (k == 1)
		printf("4");

}
