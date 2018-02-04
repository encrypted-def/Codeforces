#include <stdio.h>
#include <vector>
using namespace std;
int n;
int a[200003];
char state[200003];
bool isMoveable[200003]; // 1에 속해서 변동이 가능한 곳인지 아닌지.
bool chkElem(int st, int en) {
	vector<int> V(en - st + 1);
	for (int i = st; i <= en; i++) {
		isMoveable[i] = true;
		if (a[i] <= st || a[i] > en + 1)
			return false;
		V[a[i] - st - 1] = 1;
	}
	for (int i = 0; i < en - st + 1; i++) {
		if (!V[i])
			return false;
	}
	return true;
}
int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%s", state);
	int st = 0;
	bool isbegin = false;
	for (int i = 0; i < n; i++) {
		if (state[i] == '0') {
			if (!isbegin)
				continue;
			else {
				if (!chkElem(st, i)) {
					printf("NO");
					return 0;
				}
				else
					isbegin = false;
			}
		}
		if (state[i] == '1') {
			if (!isbegin) {
				isbegin = true;
				st = i;
			}
		}
	}
	if (isbegin) {
		if (!chkElem(st, n - 1)) {
			printf("NO");
			return 0;
		}
	}
	for (int i = 0; i < n; i++) {
		if (!isMoveable[i] && a[i] != i + 1) {
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}
