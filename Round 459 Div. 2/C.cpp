#include <string.h>
#include <stdio.h>
int main(void) {
	char s[5003];
	scanf("%s", s);
	int len = strlen(s);
	int ans = 0;
	for (int st = 0; st <= len-2; st++) {
		int val = 0; // (이면 +1, )이면 -1
		int q = 0; // 물음표 등장 횟수
		int i = st;
		while (i < len) {
			if (s[i] == '(')
				val++;
			else if (s[i] == '?') {
				q++;
			}
			else { // (s[i] == ')')
				val--;
			}
			if (val < q) {
				int diff = (q - val+1) / 2;
				val += diff;
				q -= diff;
			}
			if (q < 0) // 쓸 수 있는 question이 없으면
				break;
			if ((i - st) % 2 == 1) { // 일단 짝이 맞아야하니
				if (val <= q) { // q를 -1로 변환해서 val을 커버할 수 있는 상황이면
					ans++;
				}
			}
			i++;
		}
	}
	printf("%d", ans);
}
