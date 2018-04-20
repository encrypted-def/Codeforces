#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
#define X first
#define Y second
char num[20];
int pow10[10] = { 1,10,100,1000,10000,100000,1000000,
10000000,100000000,1000000000 };
int s2i(vector<int> v) {
	int val = 0;
	int cnt = 0;
	for (int i = 0; i < v.size(); i++)
		cnt += v[i];
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 1) {
			val += pow10[cnt-1] * (num[i]-'0');
			cnt--;
		}
	}
	return val;

}
bool isPS(int N) {
	if (N < 0)
		return false;
	if (N == 0)
		return true;
	int d = 2;
	while (d*d <= N) {
		while (N % d == 0) {
			if (N % (d*d) != 0)
				return false;
			N = N / d / d;
		}
		d++;
	}
	if (N == 1)
		return true;
	else
		return false;
}
int main(void) {
	scanf("%s", num);
	vector<int> v;
	int len = strlen(num);
	v.resize(strlen(num), 1);
	if (isPS(s2i(v))) {
		printf("0");
		return 0;
	}
	for (int ans = 1; ans < len; ans++) {
		for (int i = 0; i < ans; i++)
			v[i] = 0;
		for (int i = ans; i < len; i++)
			v[i] = 1;
		do {
			int val = s2i(v);
			if (val < pow10[len - ans - 1]) // leading zero
				continue;
			if (isPS(val)) {
				printf("%d", ans);
				return 0;
			}
		} while (next_permutation(v.begin(), v.end()));
	}
	printf("-1");
}
