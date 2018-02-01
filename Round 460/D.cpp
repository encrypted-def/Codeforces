#include <stdio.h>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
vector<int> adj[300004];
char s[300004];
int indegree[300004];
int D[300004][26]; // D[i][0] : topological sort 이후 node i에서 alphabet A가 최대 몇 번 등장가능한가.
typedef pair<int, int> PAIR;
#define X first
#define Y second
PAIR p[300004];
vector<int> topo;
int main(void) {
	int mx = 0;
	scanf("%d %d", &n, &m);
	scanf("%s", s);
	bool forceStop = false;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &p[i].X, &p[i].Y);
	}
	sort(p, p + m);
	for(int i = 0; i < m; i++){
		int a = p[i].X;
		int b = p[i].Y;
		if (i > 0 && p[i] == p[i - 1])
			continue;
		adj[a].push_back(b);
		indegree[b]++;
		if (a == b)
			forceStop = true;
	}
	if (forceStop) {
		printf("-1");
		return 0;
	}
	queue<int> Q;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			topo.push_back(i);
			Q.push(i);
		}
	}
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		for (auto near : adj[cur]) {
			indegree[near]--;
			if (indegree[near] == 0) {
				topo.push_back(near);
				Q.push(near);
			}
		}
	}
	if (topo.size() < n) { // cycle 존재
		printf("-1");
		return 0;
	}
	for (auto i : topo) {
		D[i][s[i - 1] - 'a']++;
		mx = max(mx, D[i][s[i - 1] - 'a']);
		for (auto near : adj[i]) { // 내 이웃들 갱신
			for (int alpha = 0; alpha < 26; alpha++)
				D[near][alpha] = max(D[near][alpha], D[i][alpha]);
		}
	}
	printf("%d", mx);
}
