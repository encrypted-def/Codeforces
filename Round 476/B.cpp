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
int n, k;
char map[105][105];
int D[105][105];
void fillD(int x, int y) {
	// horizontal
	if (y + k <= n) {
		bool isT = true;
		for (int j = y; j < y + k; j++) {
			if (map[x][j] != '.') {
				isT = false;
				break;
			}
		}
		if (isT) {
			for (int j = y; j < y + k; j++)
				D[x][j]++;
		}
	}
	if (x + k <= n) {
		bool isT = true;
		for (int i = x; i < x + k; i++) {
			if (map[i][y] != '.') {
				isT = false;
				break;
			}
		}
		if (isT)
			for (int i = x; i < x + k; i++)
				D[i][y]++;
	}
}
int main(void) {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%s", map[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fillD(i, j);
		}
	}
	int mX = 0, mY = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (D[i][j] > D[mX][mY]) {
				mX = i; mY = j;
			}
		}
	}
	printf("%d %d",mX+1, mY+1);
}
