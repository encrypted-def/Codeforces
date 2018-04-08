#include <stdio.h>
#include <string.h>
char S[50003];
int cnt1, cnt2, cnt3;
int main(void) {
	scanf("%s", S);
	int len = strlen(S);
	int state = 0;
	for (int i = 0; i < len; i++) {
		if (S[i] == 'a') {
			if (state != 0) {
				printf("NO");
				return 0;
			}
			cnt1++;
		}
		else if (S[i] == 'b') {
			if (state == 2) {
				printf("NO");
				return 0;
			}
			state = 1;
			cnt2++;
		}
		else if (S[i] == 'c') {
			if (state == 0) {
				printf("NO");
				return 0;
			}
			state = 2;
			cnt3++;
		}
		else {
			printf("NO");
			return 0;
		}
	}
	if (cnt1 == 0 || cnt2 == 0) {
		printf("NO");
		return 0;
	}
	if (cnt1 == cnt3 || cnt2 == cnt3)
		printf("YES");
	else
		printf("NO");
}
