#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PAIR;

#define X first
#define Y second

int n, m;
vector<PAIR> adj[200005];
ll D[200005]; // 현재 알고있는 가장 효율적인 콘서트장까지의 cost
ll a[200005];
bool isVisited[200005];
int main(void) {
	scanf("%d %d", &n, &m);
	while (m--) {
		ll u, v;
		ll len;
		scanf("%lld %lld %lld", &u, &v, &len);
		adj[u].push_back({ v,len });
		adj[v].push_back({ u,len });
	}
	priority_queue<PAIR, vector<PAIR>, greater<PAIR> > PQ;
	for (int i = 1; i <= n; i++) {
		ll t;
		scanf("%lld", &t);
		PQ.push({t,i});
		D[i] = t;
	}
	while (!PQ.empty()) {
		PAIR current = PQ.top();
		PQ.pop();
		if (isVisited[current.Y])
			continue;
		isVisited[current.Y] = true;
		for (auto near : adj[current.Y]) {
			if (current.X + 2 * near.Y < D[near.X]) {
				D[near.X] = current.X + 2 * near.Y;
				PQ.push({ D[near.X], near.X });
			}
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%lld ", D[i]);
