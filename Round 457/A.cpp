#include <stdio.h>
bool isLucky(int h, int m) {
	return (h % 10 == 7) || (m % 10 == 7);
}
int main(void) {
	int x, h, m;
	scanf("%d %d %d", &x, &h, &m);
	int cnt = 0;
	while (!isLucky(h, m)) {
		m -= x;
		if (m < 0) {
			h--;
			m += 60;
			if (h < 0)
				h += 24;
		}
		cnt++;
	}
	printf("%d", cnt);
}
