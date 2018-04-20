#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#include <functional>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
#define X first
#define Y second
int n;
map<ll, priority_queue<ll, vector<ll>, greater<ll> > > M;
priority_queue<ll, vector<ll>, greater<ll> > suspicious;

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		ll t;
		scanf("%lld", &t);
		if (M.find(t) == M.end()) {
			priority_queue<ll, vector<ll>, greater<ll> > p;
			M[t] = p;
		}
		M[t].push(i);
		if (M[t].size() >= 2)
			suspicious.push(t);
	}
	while (!suspicious.empty()) {
		ll cur = suspicious.top();
		suspicious.pop();
		if (M[cur].size() < 2)
			continue;
		ll i1 = M[cur].top();
		M[cur].pop();
		ll i2 = M[cur].top();
		M[cur].pop();
		if (M.find(2 * cur) == M.end()) {
			priority_queue<ll, vector<ll>, greater<ll> > p;
			M[2*cur] = p;			
		}
		M[2 * cur].push(i2);
		if(M[2*cur].size() >= 2)
			suspicious.push(2 * cur);
	}
	vector<ll> tmp(n);
	for (auto it = M.begin(); it != M.end(); it++) {
		auto pq = it->second;
		while (!pq.empty()) {
			ll cur = pq.top();
			pq.pop();
			tmp[cur] = it->first;
		}
	}
	vector<ll> ans;
	for (int i = 0; i < n; i++) {
		if (tmp[i] != 0)
			ans.push_back(tmp[i]);
	}
	printf("%d\n", ans.size());
	for (auto a : ans)
		printf("%lld ", a);
}
