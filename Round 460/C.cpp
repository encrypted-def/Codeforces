#include <stdio.h>
int n, m, k;
char room[2001][2001];
int D_right[2001][2001];
int D_down[2001][2001];
int main(void) {
	int cnt = 0;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%s", room[i]);
	for (int row = 0; row < n; row++) {
		D_right[row][0] = (room[row][0] == '.');
		if (D_right[row][0] >= k)
			cnt++;
		for (int col = 1; col < m; col++) {
			D_right[row][col] = (D_right[row][col - 1] + 1)*(room[row][col] == '.');
			if (D_right[row][col] >= k)
				cnt++;
		}
	}
	for (int col = 0; col < m; col++) {
		D_down[0][col] = (room[0][col] == '.');
		if (D_down[0][col] >= k)
			cnt++;
		for (int row = 1; row < n; row++) {
			D_down[row][col] = (D_down[row - 1][col] + 1)*(room[row][col] == '.');
			if (D_down[row][col] >= k)
				cnt++;
		}
	}
	if (k == 1)
		cnt /= 2;
	printf("%d", cnt);
}
