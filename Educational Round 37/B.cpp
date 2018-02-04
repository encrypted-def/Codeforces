#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
int l[5001];
int r[5001];
int main(void) {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d %d", &l[i], &r[i]);
		int curTime = l[0];
		int i = 0;
		while(i < n){
			if (curTime < l[i]) {
				curTime++;
				continue;
			}
			else if (l[i] <= curTime && curTime <= r[i]) {
				printf("%d ", curTime);
				curTime++;
				i++;
			}
			else { // r[i]를 지났으면
				printf("0 ", curTime);
				i++;
			}
		}
		printf("\n");
	}
}
