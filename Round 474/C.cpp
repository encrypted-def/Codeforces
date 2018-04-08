#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
#include <tuple>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> pi4;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int X, d;
ll calc(int seqlen) {
	return (1 << seqlen) - 1;
}
int main(void) {
	scanf("%d %d", &X, &d);
	int n = 0;
	vector<ll> ans;
	ll st = 1;
	int seqlen = 30;
		while (X > 0) {
			if (calc(seqlen) > X) {
				seqlen--;
				continue;
			}
			if (seqlen == 0)
				break;
			if (ans.size() > 10000)
				break;
			for (ll i = st; i < st + seqlen; i++)
				ans.push_back(st);
			X -= calc(seqlen);
			st = st + 2 * seqlen + 2 * d;
		}
		if (ans.size() > 10000 || seqlen == 0) {
			printf("-1");
		}
		else {
			printf("%d\n", ans.size());
			for (auto i : ans)
				printf("%lld ", i);
		}
		return 0;
}
