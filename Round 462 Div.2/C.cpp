#include <stdio.h>
#include <algorithm>
using namespace std;
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> PAIR;
int n;
int p[2005];
PAIR seg[2005]; // {1 or 2, 갯수}
int D1[2005]; // D1[i] : seg[i]까지 이어진 1의 갯수
int D2[2005]; // D1[i] : seg[i]부터 이어질 2의 갯수
int D3[2005][2005]; // D3[i][j] : seg[i]~seg[j] 뒤집었을 떄 수열에 편입시킬 수 있는 최대갯수
int main(void) {
	scanf("%d", &n);
	int idx = 0;
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		if (p[i] == 1)
			cnt1++;
		else
			cnt2++;
		if (i == 0) {
			seg[idx] = { p[i], 1 };
			continue;
		}
		if (seg[idx].X == p[i])
			seg[idx].Y++;
		else
			seg[++idx] = { p[i], 1 };
	}
	if (seg[0].X == 1)
		D1[0] = seg[0].Y;
	for (int i = 1; i <= idx; i++) {
		D1[i] = D1[i - 1];
		if (seg[i].X == 1)
			D1[i] += seg[i].Y;
	}
	if (seg[idx].X == 2)
		D2[idx] = seg[idx].Y;
	for (int i = idx - 1; i >= 0; i--) {
		D2[i] = D2[i + 1];
		if (seg[i].X == 2)
			D2[i] += seg[i].Y;
	}
	for (int i = 0; i <= idx; i++) {
		D3[i][i] = seg[i].Y;
		//printf("%d %d %d\n", i, i, D3[i][i]);
		int en1 = 0; // 뒤집는 구간에서 끝이 1인 경우.(1만 편입시킬 수 있음)
		int en2 = 0; // 뒤집는 구간에서 끝이 2인 경우.(1 혹은 2 둘다 편입 가능)
		if (seg[i].X == 1)
			en1 = seg[i].Y;
		else
			en2 = seg[i].Y;
		for (int j = i + 1; j <= idx; j++) {
			if (seg[j].X == 1)
				en1 = max(en1, en2) + seg[j].Y;
			else
				en2 = en2 + seg[j].Y;
			D3[i][j] = max(en1, en2);
			//printf("%d %d %d, %d %d\n", i, j, D3[i][j], en1, en2);
		}
	}
	int ans = max(D1[idx], D2[0]);
	for (int i = 0; i <= idx - 1; i++)
		ans = max(ans, D1[i] + D2[i + 1]);
	for (int i = 0; i <= idx - 1; i++) {
		for (int j = i + 1; j <= idx; j++) {
			if (i == 0)
				ans = max(ans, D2[j + 1] + D3[i][j]);
			else
				ans = max(ans, D1[i - 1] + D2[j + 1] + D3[i][j]);
		}
	}
	printf("%d", ans);
}
