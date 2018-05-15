#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
#define X first
#define Y second
int n, m, cl, ce, v;
int l[100004];
int e[100004];

int leftstair(int place) {
	if (cl == 0)
		return -1;
	if (place < l[0])
		return -1;
	return *(lower_bound(l, l + cl, place) - 1);
}
int rightstair(int place) {
	if (cl == 0)
		return -1;
	if (place > l[cl - 1])
		return -1;
	return *(lower_bound(l, l + cl, place));
}
int leftel(int place) {
	if (ce == 0)
		return -1;
	if (place < e[0])
		return -1;
	return *(lower_bound(e, e + ce, place) - 1);
}
int rightel(int place) {
	if (ce == 0)
		return -1;
	if (place > e[ce-1])
		return -1;
	return *(lower_bound(e, e + ce, place));
}
int calc_stair(int x1, int y1, int x2, int y2, int stair) {
	if (stair == -1) return 0x7f7f7f7f;
	return abs(x1 - x2) + abs(y1 - stair) + abs(y2 - stair);
}
int calc_elevator(int x1, int y1, int x2, int y2, int el) {
	if (el == -1) return 0x7f7f7f7f;
	return (abs(x1 - x2)+v-1)/v + abs(y1 - el) + abs(y2 - el);
}

int main(void) {
	scanf("%d %d %d %d %d", &n, &m, &cl, &ce, &v);
	for (int i = 0; i < cl; i++)
		scanf("%d", &l[i]);
	for (int i = 0; i < ce; i++)
		scanf("%d", &e[i]);
	int q;
	scanf("%d", &q);
	while (q--) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		if (x1 == x2){
			printf("%d\n", abs(y1 - y2));
			continue;
		}
		int ans = 0x7f7f7f7f;
		int lsy1 = leftstair(y1);
		int lsy2 = leftstair(y2);
		int lse1 = leftel(y1);
		int lse2 = leftel(y2);
		int rsy1 = rightstair(y1);
		int rsy2 = rightstair(y2);
		int rse1 = rightel(y1);
		int rse2 = rightel(y2);
		ans = min(ans, calc_stair(x1,y1,x2,y2,lsy1));
		ans = min(ans, calc_stair(x1, y1, x2, y2, lsy2));
		ans = min(ans, calc_stair(x1, y1, x2, y2, rsy1));
		ans = min(ans, calc_stair(x1, y1, x2, y2, rsy1));
		ans = min(ans, calc_elevator(x1, y1, x2, y2, lse1));
		ans = min(ans, calc_elevator(x1, y1, x2, y2, lse2));
		ans = min(ans, calc_elevator(x1, y1, x2, y2, rse1));
		ans = min(ans, calc_elevator(x1, y1, x2, y2, rse1));
		printf("%d\n", ans);

	}

}
