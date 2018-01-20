#include <stdio.h>
int n, q;
int arr[500003];
int gcdseg[2000010];
int gcd(int a, int b) {
	if (a == 0)
		return b;
	else
		return gcd(b%a, a);
}
int gcdupdate(int i, int val, int node, int node_st, int node_en) { // a[i]가 val로 변경된 상황
	if (node_st > i || i > node_en) // i번째 값을 입력받았는데 node_st~node_en 범위 안에 i가 없을 경우
		return gcdseg[node];
	if (node_st == node_en) // leaf에 도달한 경우
		return gcdseg[node] = val;
	int mid = (node_st + node_en) / 2;
	return gcdseg[node] = gcd(gcdupdate(i, val, node * 2, node_st, mid), gcdupdate(i, val, node * 2 + 1, mid + 1, node_en));
}
int gcdquery(int a, int b, int node, int node_st, int node_en, int x) { // gcd를 x로 만들기 위해 수정해야하는 leaf의 갯수를 반환
	if (node_en < a || b < node_st) // a~b와 node_st~node_en 범위가 아예 겹치지 않는 경우
		return 0;
	if (node_st == node_en) // leaf인 경우
		return (arr[node_st] % x != 0); // x로 나누어떨어지지 않으면 수정해야하는 leaf
	if (a <= node_st && node_en <= b) { // node_st~node_en 범위가 a~b 범위 안에 완벽하게 들어가는 경우
		if (gcdseg[node] % x == 0)
			return 0;
		if (gcdseg[2 * node + 1] % x != 0 && gcdseg[2 * node] % x != 0)
			return 2;
	}
	int mid = (node_st + node_en) / 2;
	return gcdquery(a, b, node * 2, node_st, mid, x) + gcdquery(a, b, node * 2 + 1, mid + 1, node_en, x);
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		gcdupdate(i, arr[i], 1, 1, n);
	}
	scanf("%d", &q);
	while (q--) {
		int option;
		scanf("%d", &option);
		if (option == 1) {
			int l, r, x;
			scanf("%d %d %d", &l, &r, &x);
			if (gcdquery(l, r, 1, 1, n, x) <= 1)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else {
			int i, y;
			scanf("%d %d", &i, &y);
			gcdupdate(i, y, 1, 1, n);
			arr[i] = y;
		}
	}
}
