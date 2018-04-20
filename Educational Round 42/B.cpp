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
int n, a, b;
char s[200006];
int main(void) {
	scanf("%d %d %d", &n, &a, &b);
	scanf("%s", s);
	if (a == 0 && b == 0) {
		printf("0");
		return 0;
	}
	int tot = a + b;
	if (s[0] == '.') {
		if (a < b) {
			s[0] = 'b';
			b--;
		}
		else {
			s[0] = 'a';
			a--;
		}
	}
	for (int i = 1; i < n; i++) {
		if (s[i] == '*')
			continue;
		if (s[i - 1] == '*' || s[i-1] == '.') {
			if (a < b) {
				if (b == 0)
					continue;
				s[i] = 'b';
				b--;
			}
			else {
				if (a == 0)
					continue;
				s[i] = 'a';
				a--;
			}
		}
		else if (s[i - 1] == 'a') {
			if (b == 0)
				continue;
			s[i] = 'b';
			b--;
		}
		else if(s[i-1] == 'b'){
			if (a == 0)
				continue;
			s[i] = 'a';
			a--;
		}
	}
	printf("%d", tot - a - b);
}
